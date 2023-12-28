#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

void readFile(const char* fileName, int &n){
    ifstream inputFile(fileName);
    if (inputFile.is_open()) {
        inputFile >> n;
        inputFile.close();
    }
    else{
        cerr << "Error! Can not open file to read." << endl;
    }
}

void writeFile(const char* fileName, int n){
    ofstream outputFile(fileName);
    if (outputFile.is_open()){
        outputFile << n;
        outputFile.close();
    }
    else{
        cerr << "Error! Can not open file to write." << endl;
    }
}

bool is_prime(int n){   // O(sqrt(n))
    if (n < 2) return false;
    if (n == 2) return true;

    for (int i = 2; i * i <= n; i++){
        if (n % i == 0) return false; 
    }
    return true;
}

// Dynamic Programing
/*
Khi duyệt qua từng giá trị v tăng dần trong khoảng 2-n
- Lưu trữ một mảng các số nguyên tố <= 2v (mỗi lần xét v mới, kiểm tra xem 2v-1 và 2v có phải là số nguyên tố không, nếu phải thì add vô danh sách)
- Đưa bài toán tính g(v) trở về đếm số cặp (p,q) trên mảng sao cho p+q = 2*v

=> Không cần phải dùng vòng lặp để kiểm tra từng số có phải nguyên tố không khi xét một số v mới
*/

int calculate_g(int n, vector<int>& dp){    // O(m^2) - m = dp.size()
    //sử dụng 2 con trỏ duyệt qua hết dp
    //con trỏ thứ 2 chạy từ vị trí con trỏ 1 --> đảm bảo các bộ tìm được đều khác nhau
    int count = 0;
    for (vector<int>::iterator p1 = dp.begin(); p1 != dp.end(); p1++){
        for (vector<int>::iterator p2 = p1; p2 != dp.end(); p2++){
            if (*p1 + *p2 == 2 * n)
                count++;
        }
    }
    return count;
}

int calculate_g_plus(int n, vector<int>& dp){    // O(m*log(m)) - m = dp.size()
    //sử dụng 2 con trỏ duyệt qua hết dp
    //con trỏ thứ 2 chạy từ vị trí con trỏ 1 --> đảm bảo các bộ tìm được đều khác nhau
    int count = 0;
    for (int p : dp){
        if (p >= n && binary_search(dp.begin(), dp.end(), 2*n - p))
            count++;
    }
    return count;
}

int dp_solution(int n){     //O(n^1.5)
    if (n < 2) return 0;
    vector<int> dp = {2};
    int count = 0;
    for (int v = 2; v <= n; v++){
        if (is_prime(2*v-1)) dp.push_back(2*v-1);
        if (is_prime(2*v)) dp.push_back(2*v);
        
        //caculate g(v) and add to count        
        // count += calculate_g(v, dp);
        count += calculate_g_plus(v, dp);
    }
    return count;
}
int main(){
    int n;
    const char* inFile = "INPUT.txt";
    const char* outFile = "OUTPUT.txt";

    //Read input
    readFile(inFile, n);

    int res = 0;
    res = dp_solution(n);

    //write output
    writeFile(outFile, res);
    return 0;
}
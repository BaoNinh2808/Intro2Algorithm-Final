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

/*Ý tưởng:
- Dùng sàng nguyên tố để tạo ra mảng các số nguyên tố từ 2 -> 2n
- Với mỗi giá trị v:
    Tìm trong mảng nguyên tố từ 2 -> 2v xem có bao nhiêu cặp p,q thỏa
- Cộng hết các g(v) lại
*/

vector<int> sangNguyenTo(int n){ // O(nloglogn)
    // Tạo ra mảng số nguyên tố từ 2 --> 2n
    vector<bool> isPrime(2*n+1, true);  //mảng đánh dấu, khởi tạo tất cả = true
    vector<int> primes;   //mảng lưu các số nguyên tố

    // Duyệt qua các số từ 2 -> căn(2n) và đánh dấu các bội của nó không phải là số nguyên tố
    // O(n^2 - p^2 / p)
    for (int p = 2; p * p <= 2 * n; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= 2 * n; i += p) {
                // Duyệt từ p^2 vì tất cả các bội của p từ 2p --> p^2-1 đã được đánh dấu trong các lần duyệt trước đó
                // bởi các số nguyên tố nhỏ hơn đã được duyệt trước đó và đánh dấu các bội của chúng
                isPrime[i] = false;
            }
        }
    }

    for (int p = 2; p <= 2 * n; ++p) {
        if (isPrime[p]) {
            primes.push_back(p);
        }
    }

    return primes;
}

// Tìm số lượng cặp số nguyên tố thỏa mãn điều kiện
int countPrimePairs(int n, vector<int>& primes) {
    int count = 0;

    for (int p : primes) {
        if (p >= n && p < 2 * n && binary_search(primes.begin(), primes.end(), 2 * n - p)) {
            count++;
        }
        if (p >= 2*n) break;    //Dừng sớm
    }

    return count;
}

// Tính giá trị của fn = g2 + g3 + ... + gn
int sangNguyenTo_solution(int n) {
    vector<int> primes = sangNguyenTo(n);
    int fn = 0;
    for (int i = 2; i <= n; ++i) {
        fn += countPrimePairs(i, primes);
    }
    return fn;
}

int main(){
    int n;
    const char* inFile = "INPUT.txt";
    const char* outFile = "OUTPUT.txt";

    //Read input
    readFile(inFile, n);

    int res = 0;
    res = sangNguyenTo_solution(n);

    //write output
    writeFile(outFile, res);
    return 0;
}
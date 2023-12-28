#include <iostream>
#include <fstream>
#include <vector>
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

/* 
Naive Solution: Using 3 nested loop 
    -> iterate through from 2 - n and for each value using 2 loop for find all (p,q) satisfied
    
    count = 0
    for each value v (2 <= i <= n):
        for p from 2 to 2v:
            if is_prime(p):
            for q from p to 2v:
                if is_prime(q) and (p+q = 2*v):
                    count <- count + 1

    DPT: O(n^3.5) - 3 loops + check q is prime
*/
int naive_solution(int n){
    if (n < 2) return 0;
    int count = 0;
    for (int v = 2; v <= n; v++){
        for (int i = 2; i <= 2*v; i++){
            if (is_prime(i)){
                for (int j = i; j <= 2*v; j++){
                    if (is_prime(j) && (i+j == 2*v)){
                        count++;
                    }
                }
            }
        }
    }
    return count;
}


//Cải tiến Naive Solution
/*
Với mỗi giá trị p, không cần duyệt lần lượt q để kiểm tra. Chỉ cần kiểm tra q = 2*n - p có thỏa điều kiện số nguyên tố không (và q >= p để ko có cặp trùng)
*/
int naive_solution_plus(int n){ //O(n^2.5)
    if (n < 2) return 0;
    int count = 0;
    for (int v = 2; v <= n; v++){
        for (int p = 2; p <= 2*v; p++){
            if (is_prime(p)){
                int q = 2 * v - p;
                if (is_prime(q) && q >= p) count++; 
            }
        }
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
    //res = naive_solution(n);
    res = naive_solution_plus(n);

    //write output
    writeFile(outFile, res);
    return 0;
}
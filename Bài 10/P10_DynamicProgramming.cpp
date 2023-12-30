#include <bits/stdc++.h>

using namespace std;

void readFile(const char* fileName, int& m, int& n, vector<vector<int>>& matrix){
    ifstream inFile(fileName);
    if (inFile.is_open()){
        inFile >> m;
        inFile >> n;
        for (int i = 0; i < m; i++){
            vector<int> row;
            for (int j = 0; j < n; j++){
                int tmp;
                inFile >> tmp;
                row.push_back(tmp);
            }
            matrix.push_back(row);
        }
        inFile.close();
    }
}

void writeFile(const char* fileName, int res){
    ofstream outFile(fileName);
    if (outFile.is_open()){
        outFile << res;
        outFile.close();
    }
}

bool checkEqual(int val, int val1, int val2, int val3){
    if (val + val1 + val2 + val3 != 4 * val)
        return false;
    return true;
}

#define Tuple array<int, 2>
int dp_solution(vector<vector<int>>& matrix, int m, int n){
    int max_res = 1;

    vector<vector<Tuple>> dp;
    for (int i = 0; i < m; i++){
        vector<Tuple> row;
        for (int j = 0; j < n; j++){
            Tuple tmp = {1, matrix[i][j]};
            row.push_back(tmp);
        }
        dp.push_back(row);
    }

    for (int i = 1; i < m; i++){
        for (int j = 1; j < n; j++){
            auto [a, val] = dp[i][j];
            auto [a1, val1] = dp[i-1][j-1];
            auto [a2, val2] = dp[i-1][j];
            auto [a3, val3] = dp[i][j-1];

            if (checkEqual(val,val1,val2,val3)){
                int k = (a1 > a2) ? a2 : a1;
                int t = (a1 > a3) ? a3 : a1;
                a = (k > t) ? (t+1) : (k+1);
                if (a > max_res)
                    max_res = a;
                dp[i][j] = {a, val};
            }
        }
    }

    return max_res;
}

int main(){
    int m, n;
    vector<vector<int>> matrix;
    const char* inFile = "INPUT.txt";
    const char* outFile = "OUTPUT.txt";

    //readFile
    readFile(inFile, m, n, matrix);
    
    int res = dp_solution(matrix, m, n);

    //writeFile
    writeFile(outFile, res);
    return 0;  
}
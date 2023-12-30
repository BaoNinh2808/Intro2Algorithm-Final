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

bool isUniformSquare(vector<vector<int>>& prefix_sum, int i, int j, int k){
    int row_in_prefixsum = i+1;
    int col_in_prefixsum = j+1;
    int sumSquare = prefix_sum[row_in_prefixsum+k-1][col_in_prefixsum+k-1] - prefix_sum[row_in_prefixsum-1][col_in_prefixsum+k-1] - prefix_sum[row_in_prefixsum+k-1][col_in_prefixsum-1] + prefix_sum[row_in_prefixsum-1][col_in_prefixsum-1];
    if (sumSquare == 0 || sumSquare == k * k)
        return true;
    return false;
}

int prefix_sum_solution(vector<vector<int>>& matrix, int m, int n){
    int max_res = 1;

    vector<vector<int>> prefix_sum(m+1, vector<int>(n+1, 0));
    for (int i = 1 ; i <= m; i++){
        for (int j = 1; j <= n; j++){
            prefix_sum[i][j] = prefix_sum[i][j-1] + prefix_sum[i-1][j] - prefix_sum[i-1][j-1] + matrix[i-1][j-1];
        }
    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            int a = (m-i) > (n-j) ? (n-j) : (m-i);  //min(m-i, n-j)
            for (int k = 2; k <= a; k++){     //start from square with width = 2
                if (isUniformSquare(prefix_sum, i, j, k)){
                    if (k > max_res)    
                        max_res = k;    //update result if satisfy
                }
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
    
    int res = prefix_sum_solution(matrix, m, n);

    //writeFile
    writeFile(outFile, res);
    return 0;  
}
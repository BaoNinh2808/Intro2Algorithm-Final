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

bool isUniformSquare(vector<vector<int>>& matrix, int i, int j, int k){
    int firstSquare = matrix[i][j];
    for (int row = i; row < i+k; row++){
        for (int col = j; col < j+k; col++){
            if (matrix[row][col] != firstSquare)   
                return false;
        }
    }
    return true;
}

int naive_solution(vector<vector<int>>& matrix, int m, int n){
    int max_res = 1;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            int a = (m-i) > (n-j) ? (n-j) : (m-i);  //min(m-i, n-j)
            for (int k = 2; k <= a; k++){     //start from square with width = 2
                if (isUniformSquare(matrix, i, j, k)){
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
    
    int res = naive_solution(matrix, m, n);

    //writeFile
    writeFile(outFile, res);
    return 0;  
}
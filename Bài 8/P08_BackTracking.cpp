#include <bits/stdc++.h>

using namespace std;

void readFile(const char* fileName, int& n){
    ifstream inFile(fileName);
    if (inFile.is_open()){
        inFile >> n;
        inFile.close();
    }
}

void writeFile(const char* fileName, vector<vector<vector<int>>>& res, int n){
    ofstream outFile(fileName);
    if (outFile.is_open()){
        outFile << res.size() << endl;
        for (vector<vector<int>> board : res){
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    if (board[i][j] == 1) outFile << "Q";
                    else outFile << ".";
                }
                outFile << endl;
            }
            outFile << endl;
        }
        outFile.close();
    }
}

bool find(vector<int>& vec, int key){
    for (int x : vec){
        if (x == key)  return true;
    }
    return false;
}

bool isValid(vector<vector<int>>& board, int row, int col){
    //because we put each queen in each row and valid column, so we just need check valid in diagnal
    for (int i = 0; i < row; i++){
        for (int j = 0; j < board.size(); j++){
            if (board[i][j] == 1){  //queen
                //check
                if (abs(row-i) == abs(col-j)) return false;
            }
        }
    }
    return true;
}

void tryPutQueenAtRow(vector<vector<vector<int>>>& res, int& n, vector<int>& invalidCol, vector<vector<int>>& board, int row){
    stack<int> validCol;
    for (int col = 0; col < n; col++){
        if (!find(invalidCol, col)) validCol.push(col);
    }

    while (!validCol.empty()){
        int col = validCol.top();
        validCol.pop();

        if (isValid(board, row, col)){
            //put queen at position (row,col)
            board[row][col] = 1;
            if (row == n-1){//all queen is put
                vector<vector<int>> tmp(board);
                res.push_back(tmp);
            }
            else{   
                //update invalidCol
                invalidCol.push_back(col);
                //go deeper
                tryPutQueenAtRow(res, n, invalidCol, board, row+1);
                //complete - reset invalidCol
                invalidCol.pop_back();
            }
            // reset queen at position (row, col) after complete
            board[row][col] = 0;
        }
    }

}

void solveNQueens(vector<vector<vector<int>>>& res, int n){
    vector<int> invalidCol; //store all column is not valid (already have a queen)
    vector<vector<int>> board (n, vector<int>(n, 0)); //create a 2D vector with all value is 0

    tryPutQueenAtRow(res, n, invalidCol, board, 0);

}

int main(){
    int n;
    const char* inFile = "INPUT.txt";
    const char* outFile = "OUTPUT.txt";

    //readFile
    readFile(inFile, n);
    
    vector<vector<vector<int>>> res;
    solveNQueens(res, n);

    //writeFile
    writeFile(outFile, res, n);
    return 0;  
}
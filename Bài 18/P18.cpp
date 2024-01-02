#include <bits/stdc++.h>

using namespace std;

void readFile(const char* fileName, int& n, vector<int>& arr){
    ifstream inFile(fileName);
    if (inFile.is_open()){
        inFile >> n;
        for(int i = 0; i < n; i++){
            int tmp;
            inFile >> tmp;
            arr.push_back(tmp);
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

void reverseArr(vector<int>& arr, int index){
    if (index < 2-1 || index >= arr.size()) return;

    int start = 0;
    while (start < index){
        int tmp = arr[start];
        arr[start] = arr[index];
        arr[index] = tmp;
        start++;
        index--;
    }
}

int find(vector<int>& arr, int val){
    for (int i = 0; i < arr.size(); i++){
        if (arr[i] == val) return i;
    }
    return arr.size();
}

int leastOperations(vector<int>& arr, int n){
    int curVal = 1;
    int noOps = 0;
    while (curVal <= n){
        int numOfIncreasing = 0;
        int curIndex = find(arr, curVal);
        if (curIndex == n-curVal){  //đã ở đúng vị trí
            curVal++;
            continue;
        }
        for (int i = curIndex+1; i < arr.size(); i++){
            if (arr[i] == curVal+1){
                curVal++;
                numOfIncreasing++;
            }
            else {
                break;
            }
        }
        reverseArr(arr, curIndex + numOfIncreasing);
        reverseArr(arr, numOfIncreasing);
        reverseArr(arr, n - curVal + numOfIncreasing);
        noOps += 3;
        curVal++;
    }
    return noOps + 1;
}

int main(){
    int n;
    vector<int> arr;
    const char* inFile = "INPUT.txt";
    const char* outFile = "OUTPUT.txt";

    //readFile
    readFile(inFile, n, arr);
    
    int res = leastOperations(arr, n);
    
    //writeFile
    writeFile(outFile, res);
    return 0;  
}
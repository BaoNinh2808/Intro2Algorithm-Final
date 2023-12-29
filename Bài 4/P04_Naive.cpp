#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void readFile(const char* fileName, int& n, vector<int>& nums){
    ifstream inputFile(fileName);
    if (inputFile.is_open()) {
        inputFile >> n;
        int tmp;
        for (int i = 0; i < n; i++){
            inputFile >> tmp;
            nums.push_back(tmp);
        }
        inputFile.close();
    }
    else{
        cerr << "Error! Cannot open file to read." << endl;
    }
}

void writeFile(const char* fileName, int res){
    ofstream outFile(fileName);
    if (outFile.is_open()){
        outFile << res;
        outFile.close();
    }
    else{
        cerr << "Error! Cannot open file to write." << endl;
    }
}

int naive_solution(vector<int>& nums){
    int count = 0;
    for (int i = 0; i < nums.size() - 1; i++){
        for (int j = i+1; j < nums.size(); j++){
            if (nums[i] > nums[j])
                count++;
        }
    }
    return count;
}

int main(){
    int n;
    vector<int> nums;
    const char* inFileName = "INPUT.txt";
    const char* outFileName = "OUTPUT.txt";

    //Read file
    readFile(inFileName, n, nums);

    int res = naive_solution(nums);

    //Write file
    writeFile(outFileName, res);
    return 0;
}
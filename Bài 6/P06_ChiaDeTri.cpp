#include <bits/stdc++.h>

using namespace std;

void readFile(const char* fileName, vector<vector<int>>& arr, int& k){
    ifstream inFile(fileName);
    if (inFile.is_open()){
        inFile >> k;
        inFile >> std::ws;
        for (int i = 0; i < k; i++){
            // read one line
            std::string line;
            if (std::getline(inFile, line)) {
                std::vector<int> numbers;
                std::stringstream ss(line);
                int num;
                while (ss >> num) {
                    numbers.push_back(num);
                }
                arr.push_back(numbers);
            }
        }
        inFile.close();
    }
}

void writeFile(const char* fileName, vector<int>& res){
    ofstream outFile(fileName);
    if (outFile.is_open()){
        for (int x : res){
            outFile << x << " ";
        }
        outFile.close();
    }
}


vector<int> merge(vector<int>& res, vector<int>& vec){
    vector<int> tmp;

    int i1 = 0;
    int i2 = 0;
    while (i1 < res.size() && i2 < vec.size()){
        if (res[i1] <= vec[i2]){
            tmp.push_back(res[i1]);
            i1++;
        } 
        else{
            tmp.push_back(vec[i2]);
            i2++;
        }
    }

    while (i1 < res.size()){
        tmp.push_back(res[i1]);
            i1++;
    }

    while (i2 < vec.size()){
        tmp.push_back(vec[i2]);
        i2++;
    }
    
    return tmp;
}

vector<int> ChiaDeTri(vector<vector<int>>& arr, int start, int end){
    if (start == end) return arr[start];

    int mid = (start + end) / 2;
    vector<int> top = ChiaDeTri(arr, start, mid);
    vector<int> bot = ChiaDeTri(arr, mid+1, end);

    return merge(top, bot);
}

int main(){
    vector<vector<int>> arr;
    int k;
    const char* inFileName = "INPUT.txt";
    const char* outFileName = "OUTPUT.txt";

    //readFile
    readFile(inFileName, arr, k);

    vector<int> res = ChiaDeTri(arr, 0, k-1);

    //write File
    writeFile(outFileName, res);
    return 0;
}

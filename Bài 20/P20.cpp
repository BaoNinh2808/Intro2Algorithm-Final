#include <bits/stdc++.h>

using namespace std;

void readFile(const char* fileName, int& n, vector<int>& arr){
    ifstream inFile(fileName);
    if (inFile.is_open()){
        std::string line;
        while (getline(inFile, line)) { // Đọc từng dòng trong file
            std::istringstream iss(line);
            int number;
            while (iss >> number) { // Phân tách số từ chuỗi
                arr.push_back(number);
            }
        }
        n = arr[arr.size()-1];
        arr.pop_back();
        inFile.close();
    }
}

void writeFile(const char* fileName, int res, vector<int>& res_arr){
    ofstream outFile(fileName);
    if (outFile.is_open()){
        outFile << res << "\n";
        for (int i = 0; i < res_arr.size(); i++){
            outFile << res_arr[i] << " ";
        }
        outFile.close();
    }
}

int giai_thua(int n){
    if (n == 0) return 1;
    if (n == 1) return 1;
    return n * giai_thua(n-1);
}

int findPosInRest(vector<int>& restElement, int val){
    for (int i = 0; i < restElement.size(); i++){
        if (val == restElement[i])
            return i;
    }
    return 0;
}

int findIndexFromArray(vector<int>& arr, vector<int>& restElement, int pos, int startIndex){
    if (pos == arr.size() - 1){ //phần tử cuối
        return startIndex + findPosInRest(restElement, arr[pos]);
    }

    int n = arr.size() - pos;
    int posInRest = findPosInRest(restElement, arr[pos]);
    startIndex += posInRest * giai_thua(n-1);
    restElement.erase(restElement.begin() + posInRest);

    return findIndexFromArray(arr, restElement, pos+1, startIndex);
}

void findArrayFromPos(int pos, vector<int>& restElement, vector<int>& res){
    if (restElement.size() == 1){
        res.push_back(restElement[0]);
        return;
    }

    int n = restElement.size();
    int index_of_first_element = (pos-1) / giai_thua(n-1);
    res.push_back(restElement[index_of_first_element]);
    restElement.erase(restElement.begin() + index_of_first_element);
    int new_pos = pos - index_of_first_element * giai_thua(n-1);
    findArrayFromPos(new_pos, restElement, res);
}

std::vector<int> createVector(int n) {
    std::vector<int> numbers;
    for (int i = 1; i <= n; ++i) {
        numbers.push_back(i);
    }
    return numbers;
}

int main(){
    int pos;
    vector<int> arr;
    const char* inFile = "INPUT.txt";
    const char* outFile = "OUTPUT.txt";

    //readFile
    readFile(inFile, pos, arr);
    
    int n = arr.size();

    vector<int> restElement = createVector(n);
    int res = findIndexFromArray(arr, restElement, 0, 1);

    restElement = createVector(n);
    vector<int> result;
    findArrayFromPos(pos, restElement, result);

    //writeFile
    writeFile(outFile, res, result);
    return 0;  
}
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


#define Tuple array<int, 3>

int main(){
    vector<vector<int>> arrs;
    int k;
    const char* inFileName = "INPUT.txt";
    const char* outFileName = "OUTPUT.txt";

    //readFile
    readFile(inFileName, arrs, k);

    //định nghĩa priority queue theo min heap
    priority_queue<Tuple, vector<Tuple>, greater<Tuple>> pq;

    //thêm các phần tử đầu tiên của mỗi dãy vào priority queue
    for (int i = 0; i < k; i++){
        pq.push({arrs[i][0], i, 0});
    }

    vector<int> res;
    //lần lượt lấy phần tử đầu tiên của priority queue ra và thêm vào ans
    //khi lấy một phần tử ra thì thêm phần tử tiếp theo trong dãy vào pq
    while (!pq.empty()){
        auto [val, i, j] = pq.top(); pq.pop();
        res.push_back(val);
        if (j + 1 < arrs[i].size()){    //dãy này có phần tử tiếp theo
            pq.push({arrs[i][j+1], i, j+1});
        }
    }

    //write File
    writeFile(outFileName, res);
    return 0;
}

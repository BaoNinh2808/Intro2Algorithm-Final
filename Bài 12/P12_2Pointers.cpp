#include <bits/stdc++.h>

using namespace std;

void readFile(const char* fileName, int& S){
    ifstream inFile(fileName);
    if (inFile.is_open()){
        inFile >> S;
        inFile.close();
    }
}

void writeFile(const char* fileName, vector<vector<int>> res){
    ofstream outFile(fileName);
    if (outFile.is_open()){
        if (res.size() == 0){
            outFile << "Impossible";
            return;
        }
        for (int i = 0; i < res.size(); i++){
            for (int j = 0; j < res[i].size(); j++){
                outFile << res[i][j] << " ";
            }
            outFile << endl;
        }
        outFile.close();
    }
}

vector<int> find_a_b(int S){
    int a = 0;
    int b = int(sqrt(S)+1);
    while (a <= b){
        if (a*a + b*b == S){
            return vector<int> {a,b};
        }
        if (a*a + b*b < S){
            a++;
        }
        else{
            b--;
        }
    }
    return vector<int> ();
}

int main(){
    int S;
    const char* inFile = "INPUT.txt";
    const char* outFile = "OUTPUT.txt";

    //readFile
    readFile(inFile, S);
    
    vector<vector<int>> res;
    vector<int> ab = find_a_b(S);
    if (ab.size() == 0){
        writeFile(outFile, res);
        return 0;
    }
    int a = ab[0];
    int b = ab[1];
    int lenght = a + b;
    if (lenght > 2 * pow(10, 9)){
        writeFile(outFile, res);
        return 0;
    }

    int x1 = lenght/2 - a;
    int y1 = - (lenght/2);

    int x2 = x1 + a;
    int y2 = y1 + b;

    int x3 = x2 - b;
    int y3 = y2 + a;

    int x4 = x3 - a;
    int y4 = y3 - b;

    res.push_back(vector<int> {x1,y1});
    res.push_back(vector<int> {x2,y2});
    res.push_back(vector<int> {x3,y3});
    res.push_back(vector<int> {x4,y4});

    //writeFile
    writeFile(outFile, res);
    return 0;  
}
#include <bits/stdc++.h>

using namespace std;

void readFile(const char* fileName, int& n, vector<vector<int>>& polygon){
    ifstream inFile(fileName);
    if (inFile.is_open()){
        inFile >> n;
        for (int i = 0; i < n; i++){
            vector<int> point;
            int p;
            inFile >> p;
            point.push_back(p);
            inFile >> p;
            point.push_back(p);
            polygon.push_back(point);
        }
        inFile.close();
    }
}

void writeFile(const char* fileName, vector<int> res){
    ofstream outFile(fileName);
    if (outFile.is_open()){
        outFile << res[0] << " " << res[1];
        outFile.close();
    }
}

float polygon_area(vector<vector<int>>& polygon, int start, int end){
    int sum = 0;
    for (int i = start; i <= end-1; i++){
        sum += (polygon[i+1][0] - polygon[i][0]) * (polygon[i+1][1] + polygon[i][1]);
    }
    sum += (polygon[start][0] - polygon[end][0]) * (polygon[start][1] + polygon[end][1]);
    return abs(sum) * 0.5;
}

float delta(float totalArea, float subArea){
    return fabs(2 * subArea - totalArea);
}

int findPosition(vector<vector<int>> & polygon, float Area, float& minDelta, int pivot, int start_find){
    int n = polygon.size();
    int end = start_find;    //end là biến giữ vị trí chia hình thành 2 nửa ít chênh lệch nhất
    for (int i = start_find; i < n; i++){
        if (i - pivot < 2) continue; //đảm bảo luôn có 3 điểm
        float subArea = polygon_area(polygon, pivot, i);
        float Delta = delta(Area, subArea);

        if (Delta < minDelta){
            end = i;
            minDelta = Delta;
        }
        else{   //khi delta bắt đầu tăng trở lại thì chứng tỏ vị trí trước nó chính là vị trí cần tìm
            break;
        }
    }
    return end;
}

vector<int> findDiag(vector<vector<int>> & polygon){
    int n = polygon.size();
    float Area = polygon_area(polygon, 0, n-1);

    float minDelta = Area;
    int start = 0; //start và end lưu 2 đỉnh chia hình thành 2 nửa có diện tích chênh lệch ít nhất
    //cố định P(0), tính vị trí mà chia hình thành 2 nửa có diện tích chênh lệch ít nhất
    int end = findPosition(polygon, Area, minDelta, start, 2);

    for (int p = 1; p <= n-3; p++){    //duyệt qua các điểm từ 1 -> n-3 (vì để số đỉnh còn lại >=3 nên chỉ duyệt tới n-3)
        int tmp = minDelta;
        end = findPosition(polygon, Area, minDelta, p, end);
        if (minDelta < tmp){    //đã được cập nhật
            start = p;
        }
    }

    return vector<int> {start+1, end+1};
}

int main(){
    int n;
    vector<vector<int>> polygon;
    const char* inFile = "INPUT.txt";
    const char* outFile = "OUTPUT.txt";

    //readFile
    readFile(inFile, n, polygon);
    
    vector<int> res = findDiag(polygon);

    //writeFile
    writeFile(outFile, res);
    return 0;  
}
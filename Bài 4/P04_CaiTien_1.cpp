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

int index_be_nhat_lon_hon_a_i(vector<int>& nums, int i){
    int l = 0; 
    int r = i - 1;
    int ans = i;
    while (l < r){
        int mid = (l + r + 1) / 2;
        if (nums[mid] <= nums[i]) l = mid;
        else {
            r = mid - 1;
            ans = mid;
        }
    }
    return ans;
}

int caitien_1(vector<int>& nums){
    int count = 0;
    for (int i = 1; i < nums.size(); i++){
        int lb = index_be_nhat_lon_hon_a_i(nums, i);  
        if (lb == i){ //ko co so nao trong day con lon hon a[i]
            // ko cập nhật count
            // ko can sap xep lai mang
        }
        else{
            count += (i-lb);
            //sap xep lai mang
            int tmp = nums[i];
            for (int j = lb; j < i; j++){
                nums[j+1] = nums[j];
            }
            nums[lb] = tmp;
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

    int res = caitien_1(nums);

    //Write file
    writeFile(outFileName, res);
    return 0;
}
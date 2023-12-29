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

int timSoNghichTheGiua2MangConvaSapXep(vector<int>& nums, int l, int mid, int r){
    int left = l; int right = mid+1;
    vector<int> tmp;
    int count = 0;
    while (left <= mid && right <= r){
        if (nums[left] > nums[right]){
            count += mid - left + 1;
            tmp.push_back(nums[right]);
            right++;
        }
        else{
            tmp.push_back(nums[left]);
            left++;
        }
    }

    while (left <= mid){
        tmp.push_back(nums[left++]);
    }

    while (right <= r){
        tmp.push_back(nums[right++]);
    }

    //Sao chép mảng tmp vào lại nums
    for (int i = 0; i < tmp.size(); i++){
        nums[l+i] = tmp[i];
    }
    return count;
}

int ChiaDeTri(vector<int>& nums, int l, int r){
    if (l >= r) return 0;
    if (r-l == 1){  //Có 2 phần tử
        if (nums[l] > nums[r]){ // Có nghịch thế
            int tmp = nums[l];
            nums[l] = nums[r];
            nums[r] = tmp;
            return 1;
        }
        return 0;
    }

    int mid = l + (r-l)/2;
    int result_left = ChiaDeTri(nums, l, mid);
    int result_right = ChiaDeTri(nums, mid+1, r);

    int SoNghichTheGiua2MangCon = timSoNghichTheGiua2MangConvaSapXep(nums, l, mid, r);

    return result_left + result_right + SoNghichTheGiua2MangCon;
}

int main(){
    int n;
    vector<int> nums;
    const char* inFileName = "INPUT.txt";
    const char* outFileName = "OUTPUT.txt";

    //Read file
    readFile(inFileName, n, nums);

    int res = ChiaDeTri(nums, 0, nums.size()-1);

    //Write file
    writeFile(outFileName, res);
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

void readFile(const char* fileName, int& N, int& M, vector<vector<int>>& graph){
    ifstream inFile(fileName);
    if (inFile.is_open()){
        inFile >> N;
        inFile >> M;
        for (int i = 0; i < M; i++){
            vector<int> road;
            int tmp;
            inFile >> tmp;
            road.push_back(tmp);
            inFile >> tmp;
            road.push_back(tmp);
            graph.push_back(road);
        }
        inFile.close();
    }
}

void writeFile(const char* fileName, vector<vector<int>>& res){
    ofstream outFile(fileName);
    if (outFile.is_open()){
        for (int i = 0; i < res.size(); i++){
            outFile <<"(" << res[i][0] << "-" << res[i][1] << ") : " << res[i][2] << endl;
        }
        outFile.close();
    }
}

std::vector<int> createVector(int n) {
    std::vector<int> numbers;
    for (int i = 1; i <= n; ++i) {
        numbers.push_back(i);
    }
    return numbers;
}

int findComponentIndex(vector<vector<int>>& components, int val){
    for (int i = 0; i < components.size(); i++){
        for (int x : components[i]){
            if (x == val) return i;
        }
    }
    return components.size();
}

vector<vector<int>> tao_thanh_phan_lien_thong(vector<vector<int>>& graph, int N){
    vector<bool> isUsedVetex(N+1, false);    //tạo mảng đánh dấu các phần tử đã được dùng
    vector<vector<int>> components;
    for (vector<int> road : graph){
        int u = road[0];
        int v = road[1];
        int u_componentIndex = findComponentIndex(components, u);  //index của component chứa u - trả về component.size() nếu chưa có
        int v_componentIndex = findComponentIndex(components, v);  //index của component chứa v - trả về component.size() nếu chưa có

        if (u_componentIndex == components.size() && v_componentIndex == components.size()){
            //cả 2 đều chưa thuộc thành phần liên thông nào
            //tạo một thành phần liên thông mới chứa 2 thành phần liên thông này
            vector<int> new_component = {u, v};
            isUsedVetex[u] = true;
            isUsedVetex[v] = true;
            components.push_back(new_component);
        }
        else if (u_componentIndex == components.size() && v_componentIndex < components.size()){
            // v đã nằm trong thành phần liên thông còn u thì chưa
            // thêm u vào thành phần liên thông của v
            components[v_componentIndex].push_back(u);
            isUsedVetex[u] = true;
        }
        else if (u_componentIndex < components.size() && v_componentIndex == components.size()){
            // u đã nằm trong thành phần liên thông còn v thì chưa
            // thêm v vào thành phần liên thông của u
            components[u_componentIndex].push_back(v);
            isUsedVetex[v] = true;
        }
        else{
            // cả u và v đều đã nằm trong thành phần liên thông
            if (u_componentIndex != v_componentIndex){
                //u và v nằm ở 2 thành phần liên thông khác nhau
                //gộp 2 thành phần này lại
                vector<int> new_component;
                new_component.insert(new_component.end(), components[u_componentIndex].begin(), components[u_componentIndex].end());
                new_component.insert(new_component.end(), components[v_componentIndex].begin(), components[v_componentIndex].end());
                components.push_back(new_component);
                if (u_componentIndex < v_componentIndex){
                    components.erase(components.begin() + v_componentIndex);
                    components.erase(components.begin() + u_componentIndex);
                }
                else{
                    components.erase(components.begin() + u_componentIndex);
                    components.erase(components.begin() + v_componentIndex);
                }
            }
        }
    } 

    for (int i = 1; i <= N; i++){
        if (isUsedVetex[i] == false){
            vector<int> new_component;
            new_component.push_back(i);
            components.push_back(new_component);
        }
    }
    return components;
}

int dem_so_thanh_pho_khong_den_duoc_voi_nhau(vector<vector<int>>& components){
    vector<int> components_size;
    for (int i = 0; i < components.size(); i++){
        components_size.push_back(components[i].size());
    }

    int res = 0;
    for (int i = 0; i < components_size.size()-1; i++){
        for (int j = i+1; j < components_size.size(); j++){
            res += components_size[i] * components_size[j];
        }
    }
    return res;
}

void print_2D(vector<vector<int>> & graph){
    for (vector<int> row : graph){
        cout << row[0] << " " << row[1] << endl;
    }
    cout << endl;
}

vector<vector<int>> dem_so_thanh_pho_khong_den_duoc_voi_nhau_khi_bo_moi_con_duong(vector<vector<int>>& graph, int N, int M){
    vector<vector<int>> res;
    for (int i = 0; i < M; i++){
        vector<vector<int>> new_graph;
        if (i != 0){
            new_graph.insert(new_graph.end(), graph.begin(), graph.begin()+i);
        }
        new_graph.insert(new_graph.end(), graph.begin()+i+1, graph.end());
        // print_2D(new_graph);
        vector<vector<int>> components = tao_thanh_phan_lien_thong(new_graph, N);
        int count = dem_so_thanh_pho_khong_den_duoc_voi_nhau(components);
        vector<int> tmp;
        tmp.push_back(graph[i][0]);
        tmp.push_back(graph[i][1]);
        tmp.push_back(count);
        res.push_back(tmp);
    }
    return res;
}

int main(){
    int N, M;
    vector<vector<int>> graph;
    const char* inFile = "INPUT.txt";
    const char* outFile = "OUTPUT.txt";

    //readFile
    readFile(inFile, N, M, graph);
    
    vector<vector<int>> res = dem_so_thanh_pho_khong_den_duoc_voi_nhau_khi_bo_moi_con_duong(graph, N, M);
    
    //writeFile
    writeFile(outFile, res);
    return 0;  
}
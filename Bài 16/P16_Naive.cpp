#include <bits/stdc++.h>

using namespace std;

void readFile(const char* fileName, int& n, vector<vector<int>>& tree){
    ifstream inFile(fileName);
    if (inFile.is_open()){
        inFile >> n;
        for (int i = 0; i < n-1; i++){
            vector<int> edge;
            int v;
            inFile >> v;
            edge.push_back(v);
            inFile >> v;
            edge.push_back(v);
            tree.push_back(edge);
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


/*Tree Node*/
struct TreeNode{
    int val;     // tên của đỉnh 
    TreeNode* parent;
    vector<TreeNode*> children;
};

TreeNode* buildTree(vector<vector<int>>& tree, int val, TreeNode* parent){
    TreeNode* newNode = new TreeNode();
    newNode->val = val;
    newNode->parent = parent;

    for (auto edge : tree){
        if (edge[0] == val){
            TreeNode* child = buildTree(tree, edge[1], newNode);
            newNode->children.push_back(child);
        }
    }
    return newNode;
}

void printTree(TreeNode* root){
    cout << root->val << " ";
    for (TreeNode* child : root->children){
        printTree(child);
    }
}

void deleteTree(TreeNode* root){
    for (TreeNode* child : root->children){
        deleteTree(child);
    }
    delete(root);
}

TreeNode* findNode(TreeNode* root, int val){
    if (root->val == val) return root;
    if (root->children.size() == 0){ //leaf - wrong
        return nullptr;
    }
    for (TreeNode* child : root->children){
        TreeNode* res = findNode(child, val);
        if (res != nullptr) return res;
    }
    return nullptr;     //val is not in this branch
}

int dfs(TreeNode* findingNode, TreeNode* prevNode, int u, int v, int curDistance){
    if (findingNode->val == v) return curDistance;

    for (TreeNode* child : findingNode->children){
        if (child != prevNode){ //không phải nút vừa mới gọi dfs của nút này - tránh đệ quy ngược lại
            int res = dfs(child, findingNode, u, v, curDistance+1);
            if (res != 0) return res;
        }
    }

    if (prevNode != findingNode->parent){ //nút dẫn tới nó là nút ở dưới nó - ko phải nút cha. Thì tiếp tục duyệt lên nút cha
        int parent_res = dfs(findingNode->parent, findingNode, u, v, curDistance+1);
        if (parent_res != 0) return parent_res;
    }
    
    return 0;   // không tìm thấy ở nhánh này
}

int distance(TreeNode* root, int u, int v){
    //calculate distance from u to v (u < v)
    //using dfs
    TreeNode* u_node = findNode(root, u);

    return dfs(u_node, nullptr, u, v, 0);
}

int main(){
    int n;
    vector<vector<int>> tree;
    const char* inFile = "INPUT.txt";
    const char* outFile = "OUTPUT.txt";

    //readFile
    readFile(inFile, n, tree);
    
    TreeNode* root = buildTree(tree, tree[0][0], nullptr);
    printTree(root);
    
    int res = 0;
    
    for (int u = 1; u <= n-1; u++){
        for (int v = u+1; v <= n; v++){
            res += distance(root, u, v);
        }
    }

    deleteTree(root);
    
    //writeFile
    writeFile(outFile, res);
    return 0;  
}
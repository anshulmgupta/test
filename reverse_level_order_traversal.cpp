#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int d): data(d), left(nullptr), right(nullptr) {}
};

void do_reverse_level_traversal(Node *root, vector<vector<int>> &result, int level){
    if(root == nullptr)
        return;
    if(level >= result.size()){
        result.push_back(vector<int>());
    }
    do_reverse_level_traversal(root->left, result, level+1);
    do_reverse_level_traversal(root->right, result, level+1);
    result[result.size()-level-1].push_back(root->data);
}

void print(vector<vector<int>> &result){
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout << result[i][j] << " , ";
        }
        cout << endl;
    }
}

void test_case_one(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    vector<vector<int>> result;
    do_reverse_level_traversal(root, result, 0);
    print(result);
}

int main(){
    test_case_one();
    return 0;
}

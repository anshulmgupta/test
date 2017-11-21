/*
# You are given a binary tree, find the length of the longest increasing
# sequence of this binary tree
*/


#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    Node(int val): val(val), left(nullptr), right(nullptr){}
};


void find_LIS(Node *root, Node* prev, int &max_len, int curr_len){
 
    if(root == nullptr)
      return;
  
    if(prev != nullptr && prev->val < root->val){
      curr_len++;
    }
    else
      curr_len = 1;
    
    max_len = max(max_len, curr_len);
  
    prev = root;
  
    find_LIS(root->left, prev, max_len, curr_len);
  
    find_LIS(root->right, prev, max_len, curr_len);
}

void test_case_one(){
  
    Node *root = new Node(2);
    root->left = new Node(3);
    root->right = new Node(1);
    root->left->left = new Node(4);
  
    Node *prev = nullptr;
    int max_len = 0;
    find_LIS(root, prev, max_len, 0);
  
    cout << ":: TEST_CASE_ONE ::" <<"Length of LIS = " << max_len << endl;
  
}

void test_case_two(){
  
    Node *root = nullptr;
  
    Node *prev = nullptr;
    int max_len = 0;
    find_LIS(root, prev, max_len, 0);
  
    cout << ":: TEST_CASE_TWO ::" << "Length of LIS = " << max_len << endl;
  
}

void test_case_three(){
  
    Node *root = new Node(2);
    root->left = new Node(3);
    root->right = new Node(1);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);
    
    Node *prev = nullptr;
    int max_len = 0;
    find_LIS(root, prev, max_len, 0);
    
    cout << ":: TEST_CASE_THREE ::" << "Length of LIS = " << max_len << endl;
  
}

//     1
//    3
//   2
//  3

void test_case_four(){
  
    Node *root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->left->left = new Node(3);
    
    Node *prev = nullptr;
    int max_len = 0;
    find_LIS(root, prev, max_len, 0);
    
    cout << ":: TEST_CASE_FOUR ::" <<"Length of LIS = " << max_len << endl;
  
}

int main() {
  
    test_case_one();
  
    test_case_two();
  
    test_case_three();
  
    test_case_four();
  
    return 0;
}

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

class BST{

public:

    struct Node{
        int   _val;
        Node *_left;
        Node *_right;
        Node(int val): _val(val),
                       _left(nullptr),
                       _right(nullptr){}
    };

    Node *_root = nullptr;

    void insert_helper(Node *root, int val){

        if(root == nullptr){
            _root = new Node(val);
            return;
        }
        if(val < root->_val){
            if(root->_left == nullptr){
                root->_left = new Node(val);
                return;
            }
            else
                insert_helper(root->_left, val);
        }
        else{
            if(root->_right == nullptr){
                root->_right = new Node(val);
                return;
            }
            else
                insert_helper(root->_right, val);
        }
    }

    void insert_helper(Node **root, int val){
        if(*root == nullptr){
            *root = new Node(val);
            return;
        }
        if(val < (*root)->_val){
            if((*root)->_left == nullptr){
                (*root)->_left = new Node(val);
                return;
            }
            else
                insert_helper((*root)->_left, val);
        }
        else{
            if((*root)->_right == nullptr){
                (*root)->_right = new Node(val);
                return;
            }
            else
                insert_helper((*root)->_right, val);
        }

    }

    Node* insert_helper_ret(Node *root, int val){
        if(root == nullptr){
            root = new Node(val);
        }
        else if(val < root->_val)
            root->_left = insert_helper_ret(root->_left, val);
        else
            root->_right = insert_helper_ret(root->_right, val);
        return root;
    }

    void insert(int val){
        //insert_helper(&_root, val);
        _root = insert_helper_ret(_root, val);
    }

    bool search_helper(Node *root, int val){
        if(root == nullptr)
            return false;
        if(root->_val == val) 
            return true;
        else if(val < root->_val)
            return search_helper(root->_left, val);
        else
            return search_helper(root->_right, val);
    }

    bool search(int val){
        Node *tmp = _root;
        return search_helper(tmp, val);
    }

    void inorder_helper(Node *root){
        if(root == nullptr)
            return;
        inorder_helper(root->_left);
        cout << root->_val << ",";
        inorder_helper(root->_right);
    }

    void inorder_helper_itr(Node *root){
        stack<Node*> st;
        vector<int> output;
        while(root != nullptr || !st.empty()){
            if(root != nullptr){
                st.push(root);
                root = root->_left;
            }
            else{
                root = st.top();
                output.push_back(root->_val);
                st.pop();
                root = root->_right;
            }
        }
        for_each(output.begin(), output.end(), [](int i){ cout << i << ","; });
    }

    void inorder(){
        Node *tmp = _root;
        inorder_helper_itr(tmp);
        cout << endl;
    }

};

int main(){
    BST my_bst;

    my_bst.insert(50);
    my_bst.insert(30);
    my_bst.insert(20);
    my_bst.insert(40);
    my_bst.insert(70);
    my_bst.insert(60);
    my_bst.insert(80);
    my_bst.inorder();
    cout << boolalpha << my_bst.search(20) << endl;
    cout << boolalpha << my_bst.search(80) << endl;
    cout << boolalpha << my_bst.search(21) << endl;  

    return 0;
}

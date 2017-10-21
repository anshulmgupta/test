#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node{
    int data;
    vector<Node*> childrens;
    Node(int d): data(d) {}
};

void print_level(Node *root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        auto *d = q.front();
        q.pop();
        cout << d->data << " , ";
        for(auto *child : d->childrens){
            q.push(child);
        }
    }
    cout << endl;
}

Node* clone_tree(Node *root){
    if(root == nullptr)
        return root;
 
    Node *new_root = new Node(root->data);
    for(auto *child : root->childrens){
        new_root->childrens.push_back(clone_tree(child));
    }
    return new_root;
}

void test_case_one(){
    Node *root = new Node(10);
    (root->childrens).push_back(new Node(2));
    (root->childrens).push_back(new Node(34));
    (root->childrens).push_back(new Node(56));
    (root->childrens).push_back(new Node(100));
    (root->childrens[2]->childrens).push_back(new Node(1));
    (root->childrens[3]->childrens).push_back(new Node(7));
    (root->childrens[3]->childrens).push_back(new Node(8));
    (root->childrens[3]->childrens).push_back(new Node(9));
    print_level(root);
    Node *cloned_root = clone_tree(root);
    print_level(cloned_root);
}

int main(){
    test_case_one();
    return 0;
}

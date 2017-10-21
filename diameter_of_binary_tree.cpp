#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int d): data(d), left(nullptr), right(nullptr){}
};

struct HeightDia{
    int height;
    int diameter;
};

HeightDia find_diameter(Node *root){

    if(root == nullptr)
        return {0,0};

    HeightDia res;

    HeightDia left = find_diameter(root->left);
    HeightDia right = find_diameter(root->right);

    res.height = max(left.height, right.height) + 1;

    res.diameter = max(left.height + right.height + 1, max(left.diameter, right.diameter));

    return res;
}

void test_case_one(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    auto res = find_diameter(root);
    cout << "Diameter = " << res.diameter << endl;
}

void test_case_two(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->left->right = new Node(7);
    root->left->left->left = new Node(8);
    auto res = find_diameter(root);
    cout << "Diameter = " << res.diameter << endl;
}

int main(){
    test_case_one();
    test_case_two();
    return 0;
}

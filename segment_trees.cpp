#include <iostream>
#include <queue>
#include <climits>
using namespace std;

struct Node{
    int start;
    int end;
    int value;
    Node *left;
    Node *right;
    Node(int v, int s, int e): value(v),
                               start(s),
                               end(e),
                               left(nullptr),
                               right(nullptr){}
};

int get_sum(int arr[], int s, int e){
    int sum=0;
    for(int i=s;i<=e;i++)
        sum += arr[i];
    return sum;
}

Node* construct_segment_tree(int arr[], int start, int end){
    if(start > end)
        return nullptr;
    int mid = start + (end-start)/2;
    int sum = get_sum(arr, start, end);
    Node *root = new Node(sum, start, end);
    if(start == end)
        return root;
    root->left = construct_segment_tree(arr, start, mid);
    root->right = construct_segment_tree(arr, mid+1, end);
    return root;
}

int sum_range_query(Node *root, int start, int end){
    if(root == nullptr)
        return 0;
    if(root->start >= start && root->end <= end)
        return root->value;
    if(root->end < start || end < root->start)
        return 0;
    return sum_range_query(root->left, start, end) + sum_range_query(root->right, start, end);
}

void update_query(Node *&root, int idx, int delta){
    if(root == nullptr)
        return;
    if(root->end < idx || idx < root->start)
        return;
    root->value += delta;
    update_query(root->left, idx, delta);
    update_query(root->right, idx, delta);
}

void update_data(int arr[], Node *&root, int idx, int new_val){
    int delta = new_val - arr[idx];
    arr[idx] = new_val;
    update_query(root, idx, delta);
}

void do_bfs(Node *root){
    if(root == nullptr)
        return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int sz = q.size();
        for(int i=0;i<sz;i++){
            auto *tmp = q.front();
            q.pop();
            cout << tmp->start << "," << tmp->end << "," << tmp->value << "  ";
            if(tmp->left)
                q.push(tmp->left);
            if(tmp->right)
                q.push(tmp->right);
        }
        cout << endl;
    }
}

int main(){
    int arr[] = {5,2,1,3,4,6,7,9,8,3};
    int len = sizeof(arr)/sizeof(arr[0]);
    Node *root = construct_segment_tree(arr, 0, len-1);
    do_bfs(root);
    int sum = sum_range_query(root, 2, 8);
    cout << "Sum from 2 to 8 = " << sum << endl;
    update_data(arr, root, 5, 8);
    do_bfs(root);
    sum = sum_range_query(root, 2, 8);
    cout << "Sum from 2 to 8 = " << sum << endl;
    return 0;
}

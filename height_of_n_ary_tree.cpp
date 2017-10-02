#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct Node{
  int val;
  vector<Node*> childs;
  Node(int v): val(v) {}
};

Node* add_nodes(Node *root, int src, int dst){
  if(root == nullptr){
    root = new Node(src);
    root->childs.push_back(new Node(dst));
    return root;
  }
  if(root->val == src){
    root->childs.push_back(new Node(dst));
  }
  else{
    for(auto d: root->childs){
      add_nodes(d, src, dst);
    }
  }
  return root;
}

void print_bfs(Node *root){
  Node *tmp = root;
  queue<Node*> q;
  q.push(tmp);
  while(!q.empty()){
    auto d = q.front();
    q.pop();
    cout << d->val << endl;
    for(auto ch : d->childs){
      q.push(ch);
    }
  }
}

Node *build_tree(int k, vector<int> &from, vector<int> &to){
  Node *root = nullptr;
  for(int i=0;i<from.size();i++){
    int src = from[i];
    int dst = to[i];
    root = add_nodes(root, src, dst);
  }
  return root;
}

int find_height(Node *root){
  Node *tmp = root;
  if(tmp->childs.size() == 0)
    return 0;
  int ht = 0;
  for(auto d: tmp->childs)
    ht = max(ht, find_height(d));
  return 1 + ht;
}

int main(){
  vector<int> from = {1,1,1,5,5,4};
  vector<int> to = {3,2,5,4,6,7};
  Node *root = build_tree(3, from, to);
  print_bfs(root);
  int ht = find_height(root);
  cout << "Height = " << ht << endl;
  return 0;
}

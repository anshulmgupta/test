#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

/** 
* Represents a pair relation between one parent node and one child node inside a binary tree 
* If the _parent is null, it represents the ROOT node 
*/ 

struct Relation { 
  int child;
  int parent; 
  bool isLeft; 
}; 


/** 
* Represents a single Node inside a binary tree 
*/ 
struct Node {
  int id; 
  struct Node *left; 
  struct Node *right;
  Node(int x) : id(x), left(nullptr), right(nullptr) {}
};

void inorder(struct Node* root){
  
  if (root == NULL)
    return;
    
  inorder(root->left);
  cout << root->id << endl;
  inorder(root->right);
}


int main(){
  
  vector<Relation> data;
  data.push_back({15, 20, true});
  data.push_back({19, 80, true});
  data.push_back({17, 20, false});
  data.push_back({16, 80, false});
  data.push_back({80, 50, false});
  data.push_back({50, 0, false});
  data.push_back({20, 50, true});
  
  Node* root = NULL;
  map<int,vector<Relation>> mp;
  
  for(auto d: data){
    
    if(d.parent == 0){
      root = new Node(d.child);
    }
    else if(mp.find(d.parent)!=mp.end()){
      mp[d.parent].push_back(d);
    }
    else{
      vector<Relation> v_data{d};
      mp.insert(pair<int,vector<Relation> >(d.parent, v_data));
    }
  }
  
  queue<Node*> q;
  q.push(root);
  while(!q.empty()){    
    struct Node* tmp = q.front();
    q.pop();
    if(mp.find(tmp->id)!=mp.end()){
      vector<Relation> childs = mp[tmp->id];
      for(auto ch: childs){ 
        struct Node* children = new Node(ch.child);
        q.push(children);
        if(ch.isLeft){
          tmp->left = children;
        }
        else
          tmp->right = children;
      }
    }
  }
  inorder(root);
  return 0;
}


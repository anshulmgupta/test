#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class BST {
 public:
  BST(): _root(nullptr) {}

  ~BST() {
    _delete_using_recursive_postorder(&_root);
  }

  void build_tree(vector<int>& arr) {
    for (const int& val : arr) {
      _insert_pointer(&_root, val);
      // _insert_ref(_root, val);
    }
    int inserted_nodes_count = _count_tree_nodes(&_root);
    cout << "No. of nodes inserted in the tree = " 
         << inserted_nodes_count << endl;
    assert(arr.size() == inserted_nodes_count);
  }

  void print_tree() {
    Node* tmp = _root;
    cout << "Recursive in-order traversal of the tree = ";
    _print_tree(tmp);
    cout << endl;
  }

  int predecessor(int val) {
    Node* pred =  _predecessor(&_root, val);
    if (pred) {
      return pred->value;
    }
    return -1;
  }

  void morris_inorder_traversal() {
    _morris_inorder_traversal(&_root);
    cout << endl;
  }

  void morris_preorder_traversal() {
    _morris_preorder_traversal(&_root);
    cout << endl;
  }

 private:
  struct Node {
    int value;
    Node* left;
    Node* right;
    Node(const int value):
        value(value),
        left(nullptr),
        right(nullptr) {}
  };
  Node* _root;

  void _insert_ref(Node*& root, const int value) {
    if (root == nullptr) {
      root = new Node(value);
      return;
    }
    if (root->value > value) {
      _insert_ref(root->left, value);
    } else {
      _insert_ref(root->right, value);
    }
  }

  void _insert_pointer(Node** root, const int value) {
    if (*root == nullptr) {
      *root = new Node(value);
      return;
    }
    if ((*root)->value > value) {
      _insert_pointer(&(*root)->left, value);
    } else {
      _insert_pointer(&(*root)->right, value);
    }
  }

  int _count_tree_nodes(Node** root) {
    if (*root == nullptr) {
      return 0;
    }
    int count_left = _count_tree_nodes(&(*root)->left);
    int count_right = _count_tree_nodes(&(*root)->right);
    return 1 + count_left + count_right;
  }

  void _print_tree(Node*& root) {
    if (root == nullptr) {
      return;
    }
    _print_tree(root->left);
    cout << root->value << ", ";
    _print_tree(root->right);
  }

  void _delete_using_recursive_postorder(Node** root) {
    if (*root == nullptr) {
      return;
    }
    _delete_using_recursive_postorder(&(*root)->left);
    _delete_using_recursive_postorder(&(*root)->right);
    cout << "Deleting tree node with value = " << (*root)->value << endl;
    delete *root;
    *root = nullptr;
  }

  Node* _predecessor(Node** root, int val) {
    if (*root == nullptr) {
      return nullptr;
    }
    if ((*root)->value == val) {
      if ((*root)->left) {
        Node* temp = (*root)->left;
        while(temp->right) {
          temp = temp->right;
        }
        return temp;
      }
    }
    else if ((*root)->value > val) {
      return _predecessor(&(*root)->left, val);
    } else if ((*root)->value < val) {
      return _predecessor(&(*root)->right, val);
    }
    return nullptr;
  }

  void _morris_inorder_traversal(Node** root) {
    Node* temp = *root;
    while(temp) {
      if (!temp->left) {
        cout << temp->value << ", ";
        temp = temp->right;
      } else {
        Node* pred = temp->left;
        while(pred->right != temp && pred->right) {
          pred = pred->right;
        }
        if (!pred->right) {
          pred->right = temp;
          temp = temp->left;
        } else {
          pred->right = nullptr;
          cout << temp->value << ", ";
          temp = temp->right;
        }
      }
    }
  }
 
  void _morris_preorder_traversal(Node** root) {
    Node* temp = *root;
    while(temp) {
      if (!temp->left) {
        cout << temp->value << ", ";
        temp = temp->right;
      } else {
        Node* pred = temp->left;
        while(pred->right != temp && pred->right) {
          pred = pred->right;
        }
        if (!pred->right) {
          pred->right = temp;
          cout << temp->value << ", ";
          temp = temp->left;
        } else {
          pred->right = nullptr;
          temp = temp->right;
        }
      }
    }
  }
};

int main() {
  BST bst;
  vector<int> arr = {50, 30, 20, 40, 70, 60, 80};
  bst.build_tree(arr);
  bst.print_tree();
  cout << "Predecessor = " << bst.predecessor(30) << endl;
  bst.morris_inorder_traversal();
  bst.morris_preorder_traversal();
}

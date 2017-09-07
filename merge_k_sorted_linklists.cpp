#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct Node {
    int _data;
    Node * _next;
    Node(int val): _data(val),
                   _next(nullptr){}
};

class Heap {

private:
    int __size;
    int __capacity;
    vector<Node*> _arr;
public:

    Heap(int size): __size(0),
                    __capacity(size),
                    _arr(size) {}

    void min_heapify(int idx){
        int left = left_child(idx);
        int right = right_child(idx);
        int smaller = idx;

        if(left < __size && _arr[left]->_data < _arr[smaller]->_data)
            smaller = left;

        if(right < __size && _arr[right]->_data < _arr[smaller]->_data)
            smaller = right;
  
        if(smaller != idx){
            swap(_arr[idx], _arr[smaller]);
            min_heapify(smaller);
        }
    }

    int peek_top(){
        return _arr[0]->_data;
    }

    void print_heap(){
        int sz = 0;
        while(sz != __size){
            cout << _arr[sz]->_data << ",";
            sz++;
        }
        cout << endl;
    }

    Node* pop(){
       if(__size <= 0){
           cout << "HEAP IS EMPTY!!!" << endl;
           return nullptr;
       }
       auto *val = _arr[0];
       if(__size >= 1){
           _arr[0] = _arr[__size-1];
           __size--;
           min_heapify(0);
       }
       return val;
    }

    void push(Node* h_node){
        if(__size >= __capacity){
            cout << "HEAP IF FULL!!!" << endl;
            return;
        }
      
        __size++;
        int idx = __size-1;
        _arr[idx] = h_node;
        while(idx != 0 && _arr[parent(idx)]->_data > _arr[idx]->_data){
            swap(_arr[parent(idx)], _arr[idx]);
            idx = parent(idx);
        }
    }

    int parent(int idx){
        return (idx-1)/2;
    }
 
    int left_child(int idx){
        return ((2*idx) + 1);
    }

    int right_child(int idx){
        return ((2*idx) + 2);
    }
};

struct LinkList {

    Node *_head = nullptr;

    LinkList() {}

    LinkList(Node *h): _head(h) {}

    int count(){    
        int count = 0;
        Node *tmp = _head;
        while(tmp != nullptr) {
            count++;
            tmp = tmp->_next;
        }
        return count;
    }

    void print_list(){
        cout << "Printing List..." << endl;
        Node *tmp = _head;
        while(tmp != nullptr){
            cout << tmp->_data << endl;
            tmp = tmp->_next;
        }
    }
    
    void insert_last(int val){
        Node *tmp = new Node(val);
        if(_head == nullptr){
            _head = tmp;
            return;
        }
        Node *t = _head;
        while(t->_next != nullptr)
            t = t->_next;
        t->_next = tmp;
    }
 
    Node* get_head(){
        return _head;
    }

    void set_head(Node *head){
        _head = head;
    }
};

void Method_One(){
    LinkList l1, l2, l3, result;
    l1.insert_last(2);
    l1.insert_last(6);
    l1.insert_last(12);
    l1.insert_last(34);

    l2.insert_last(1);
    l2.insert_last(9);
    l2.insert_last(20);
    l2.insert_last(1000);

    l3.insert_last(23);
    l3.insert_last(34);
    l3.insert_last(90);
    l3.insert_last(2000);
    vector<Node*> arr = { l1.get_head(), l2.get_head(), l3.get_head() };

    int k = arr.size();
    Heap my_heap(k);

    for(int i = 0; i < k; i++){
        Node *tmp = arr[i];
        my_heap.push(tmp);
    }

    while(true){
        auto *d = my_heap.pop();
        if(d == nullptr)
            break;
        result.insert_last(d->_data);

        if(d->_next != nullptr){
            d = d->_next;
            my_heap.push(d);
        }
    }

    result.print_list();
}

Node* merge(Node *l1, Node *l2){
    if(l1 == nullptr)
        return l2;
    if(l2 == nullptr)
        return l1;
    Node *res = nullptr;
    if(l1->_data <= l2->_data){
        res = l1;
        res->_next = merge(l1->_next, l2);
    }
    else{
        res = l2;
        res->_next = merge(l1, l2->_next);
    }
    return res;
}

Node* merge_div_con(vector<Node*> &arr, int start, int end){
    if(start == end)
        return arr[start];
    if(start + 1 == end)
        return merge(arr[start], arr[end]);
    int mid = (start + end)/2;
    Node *left = merge_div_con(arr, start, mid);
    Node *right = merge_div_con(arr, mid + 1, end);
    return merge(left, right);
}

void Method_Two(){
    LinkList l1, l2, l3;
    l1.insert_last(2);
    l1.insert_last(6);
    l1.insert_last(12);
    l1.insert_last(34);

    l2.insert_last(1);
    l2.insert_last(9);
    l2.insert_last(20);
    l2.insert_last(1000);

    l3.insert_last(23);
    l3.insert_last(34);
    l3.insert_last(90);
    l3.insert_last(2000);
    vector<Node*> arr = { l1.get_head(), l2.get_head(), l3.get_head() };
    //Node *h = merge_div_con(arr, 0, arr.size());
    //result.set_head(h);
    LinkList result = merge_div_con(arr, 0, arr.size());
    result.print_list();
}

int main(){
   Method_One();
   Method_Two();
   return 0;

}

#include<iostream>

using namespace std;

struct LinkList {

    struct Node {
        int _data;
        Node * _next;
        Node(int val): _data(val),
                       _next(nullptr){}
    };

    Node *_head = nullptr;

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

    void insert_first(int val){
        Node *tmp = new Node(val);
        if(_head == nullptr){
            _head = tmp;
            return;
        }
        tmp->_next = _head;
        _head = tmp;
    } 

    void reverse_iterative(){
        Node *curr = _head;
        Node *next, *prev = nullptr;
        while(curr != nullptr){
            next = curr->_next;
            curr->_next = prev;
            prev = curr;
            curr = next;
        }
        _head = prev;
    }

    Node* reverse_recursive_helper(Node* head){
        if(head == nullptr || head->_next == nullptr)
            return head;
        
        Node* new_head = reverse_recursive_helper(head->_next);
        Node* p = head->_next;
        p->_next = head;
        head->_next = nullptr;
        return new_head;
    }

    void reverse_recursive(){
        Node *tmp = _head;
        _head = reverse_recursive_helper(tmp);
    }

    Node* merge_helper(Node *a, Node *b){
        if(a == nullptr)
            return b;
        if(b == nullptr)
            return a;
  
        Node *res = nullptr;
        if(a->_data <= b->_data){
            res = a;
            res->_next = merge_helper(a->_next,b);
        }
        else {
            res = b; 
            res->_next = merge_helper(a,b->_next);
        }
        return res;
    }

    LinkList& merge(LinkList& lst) {
        Node *a = this->_head;
        Node *b = lst._head;
        Node *result = merge_helper(a,b);
        this->_head = result;
        return *this;
    }

};

int main(){
    LinkList l;
    LinkList l2;
    for(int i=1 ; i<5 ; i++)
        l.insert_last(i);
    for(int i=5 ; i<8 ; i++)
        l2.insert_last(i);

    l.reverse_iterative();
    l.print_list();
    l.reverse_recursive();
    l.print_list();
    l = l.merge(l2);
    l.print_list();
    return 0;
}

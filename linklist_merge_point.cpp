#include <iostream>

using namespace std;

struct Node{
    int val;
    Node *next;
    Node(int val): val(val),
                   next(nullptr){}
};

int length(Node *head){
    int len = 0;
    Node *tmp = head;
    while(tmp != nullptr){
        ++len;
        tmp = tmp->next;
    }
    return len;
}

void move_pointer(Node **head, int len){
    while(len != 0){
        *head = (*head)->next;
        len--;
    }
}

Node* get_intersection_point(Node *list1, Node *list2){
    int len1 = length(list1);
    int len2 = length(list2);

    cout << "Length of List One = " << len1 << endl;
    cout << "Length of List Two = " << len2 << endl;

    if(len1 > len2)
        move_pointer(&list1, len1 - len2);
    else
        move_pointer(&list2, len2 - len1);

    while(list1 != nullptr && list2 != nullptr){
        if(list1 == list2){
            return list1;
        }
        list1 = list1->next;
        list2 = list2->next;
    }

    return nullptr;
}

void test_intersection_no_cycle_exists(){
    Node* newNode;
    Node* head1 = new Node(10);
    Node* head2 = new Node(3);
    head2->next = new Node(6);
    head2->next->next = new Node(9);
    newNode = new Node(15);
    head1->next = newNode;
    head2->next->next->next  = newNode;
    newNode = new Node(30);
    head1->next->next= newNode;
    head1->next->next->next = NULL;

    Node *tmp = get_intersection_point(head1, head2);
    if(tmp == nullptr)
        cout << "Lists does not intersect!!!" << endl;
    else
        cout << "Lists intersect at Node with value : " << tmp->val << endl;
}

void insert(Node **head, int val){
    if(*head == nullptr){
        *head = new Node(val);
        return;
    }
    Node *tmp = new Node(val);
    Node *tmp_head = *head;
    while((tmp_head)->next != nullptr)
        tmp_head = (tmp_head)->next;
    (tmp_head)->next = tmp;
}

void test_intersection_no_cycle_not_exists(){
    Node* head1 = nullptr;
    Node* head2 = nullptr;
    insert(&head1, 3);
    insert(&head1, 6);
    insert(&head1, 9);
    insert(&head1, 15);
    insert(&head1, 30);

    insert(&head2, 10);
    insert(&head2, 15);
    insert(&head2, 30);
    Node *tmp = get_intersection_point(head1, head2);
    if(tmp == nullptr)
        cout << "Lists does not intersect!!!" << endl;
    else
        cout << "Lists intersect at Node with value : " << tmp->val << endl;
}

int main(){

    test_intersection_no_cycle_exists();

    test_intersection_no_cycle_not_exists();

    return 0;

}

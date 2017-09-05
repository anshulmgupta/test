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

int length(Node *head1, Node *head2){
    int len = 0;
    while(head1 != head2){
        ++len;
        head1 = head1->next;
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

Node* has_cycle(Node *head){
    Node *slow = head;
    Node *fast = head;

    while(slow != nullptr && fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return slow;
    }
    return nullptr;
}

Node* cycle_start(Node *head){
    Node *cycle_loop_node = has_cycle(head);
    if(cycle_loop_node == nullptr)
        return nullptr;
    while(head != cycle_loop_node){
        head = head->next;
        cycle_loop_node = cycle_loop_node->next;
    }
    return cycle_loop_node;
}

Node* get_intersection_point_cycle(Node *list1, Node *list2){
    Node *cycle_start_node1 = cycle_start(list1);
    Node *cycle_start_node2 = cycle_start(list2);

    if(cycle_start_node1 == nullptr && cycle_start_node2 == nullptr)
        return get_intersection_point(list1, list2);
    else if(cycle_start_node1 == nullptr && cycle_start_node2 != nullptr)
        return nullptr;
    else if(cycle_start_node1 != nullptr && cycle_start_node2 == nullptr)
        return nullptr;

    Node *tmp = cycle_start_node2;
    tmp = tmp->next;
    while(tmp != cycle_start_node1 && tmp != cycle_start_node2)
        tmp = tmp->next;

    if(tmp != cycle_start_node1)
        return nullptr;

    int len1 = length(list1, cycle_start_node1);
    int len2 = length(list2, cycle_start_node2);

    if(len1 > len2)
        move_pointer(&list1, len1 - len2);
    else
        move_pointer(&list2, len2 - len1);

    while(list1 != list2 && list1 != cycle_start_node1 && list2 != cycle_start_node2){
        list1 = list1->next;
        list2 = list2->next;
    }

    if(list1 == list2)
        return list1;
    else if(list1 == cycle_start_node1)
        return list1;
    else
        return list2;
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

void insert(Node **head1, Node **head2, int val){
    if(*head1 == nullptr && *head2 == nullptr){
        Node *t = new Node(val);
        *head1 = t;
        *head2 = t;
        return;
    }

    Node *tmp = new Node(val);
    Node *tmp_head1 = *head1;
    Node *tmp_head2 = *head2;
    while((tmp_head1)->next != nullptr)
        tmp_head1 = (tmp_head1)->next;

    while((tmp_head2)->next != nullptr)
        tmp_head2 = (tmp_head2)->next;

    (tmp_head1)->next = tmp;

    (tmp_head2)->next = tmp;
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

void create_cycle(Node **head){
    Node *tmp = *head;
    while(tmp->next != nullptr)
        tmp = tmp->next;
    tmp->next = (*head)->next->next;
}

void test_has_cycle(){
    Node* head1 = nullptr;
    insert(&head1, 3);
    insert(&head1, 6);
    insert(&head1, 9);
    insert(&head1, 15);
    insert(&head1, 30);
    create_cycle(&head1);
    Node *cycle = has_cycle(head1);
    if(cycle == nullptr)
        cout << "No Cycle Exists!!!" << endl;
    else
        cout << "Cycle Exists!!!" << endl;
}

void test_has_no_cycle(){
    Node* head1 = nullptr;
    insert(&head1, 3);
    insert(&head1, 6);
    insert(&head1, 9);
    insert(&head1, 15);
    insert(&head1, 30);
    Node *cycle = has_cycle(head1);
    if(cycle == nullptr)
        cout << "No Cycle Exists!!!" << endl;
    else
        cout << "Cycle Exists!!!" << endl;
}

void test_start_cycle(){
    Node* head1 = nullptr;
    insert(&head1, 3);
    insert(&head1, 6);
    insert(&head1, 9);
    insert(&head1, 15);
    insert(&head1, 30);
    create_cycle(&head1);
    Node *cycle = cycle_start(head1);
    if(cycle == nullptr)
        cout << "No Cycle Exists!!!" << endl;
    else
        cout << "Cycle Exists At Node = " << cycle->val  << endl;
}

void test_start_no_cycle(){
    Node* head1 = nullptr;
    insert(&head1, 3);
    insert(&head1, 6);
    insert(&head1, 9);
    insert(&head1, 15);
    insert(&head1, 30);
    Node *cycle = cycle_start(head1);
    if(cycle == nullptr)
        cout << "No Cycle Exists!!!" << endl;
    else
        cout << "Cycle Exists At Node = " << cycle->val  << endl;
}

void test_intersection_cycle_before(){
    Node *head1 = nullptr;
    Node *head2 = nullptr;
    insert(&head2, 11);
    insert(&head2, 14);
    insert(&head1, 3);
    insert(&head1, &head2, 6);
    insert(&head1, 9);
    insert(&head1, 15);
    insert(&head1, 30);
    create_cycle(&head1);

    Node *tmp = get_intersection_point_cycle(head1, head2);
    
    if(tmp == nullptr)
        cout << "Lists does not intersect!!!" << endl;
    else
        cout << "Lists intersect at Node with value : " << tmp->val << endl;
}

void test_intersection_cycle_after(){
    Node *head1 = nullptr;
    Node *head2 = nullptr;
    insert(&head2, 11);
    insert(&head2, 14);
    insert(&head1, 3);
    insert(&head1, 6);
    insert(&head1, 9);
    insert(&head1, &head2, 15);
    insert(&head1, 30);
    create_cycle(&head1);

    Node *tmp = get_intersection_point_cycle(head1, head2);

    if(tmp == nullptr)
        cout << "Lists does not intersect!!!" << endl;
    else
        cout << "Lists intersect at Node with value : " << tmp->val << endl;
}

void test_no_intersection_one_cycle_one_not(){
    Node *head1 = nullptr;
    Node *head2 = nullptr;
    insert(&head2, 11);
    insert(&head2, 14);
    insert(&head2, 15);
    insert(&head2, 30);
    insert(&head1, 3);
    insert(&head1, 6);
    insert(&head1, 9);
    insert(&head1, 15);
    insert(&head1, 30);
    create_cycle(&head1);

    Node *tmp = get_intersection_point_cycle(head1, head2);

    if(tmp == nullptr)
        cout << "Lists does not intersect!!!" << endl;
    else
        cout << "Lists intersect at Node with value : " << tmp->val << endl;
}

int main(){
    cout << "===============Test Case 1=====================" << endl;
    test_intersection_no_cycle_exists();
    cout << "===============Test Case 2=====================" << endl;
    test_intersection_no_cycle_not_exists();
    cout << "===============Test Case 3=====================" << endl;
    test_has_cycle();
    cout << "===============Test Case 4=====================" << endl;
    test_has_no_cycle();
    cout << "===============Test Case 5=====================" << endl;
    test_start_cycle();
    cout << "===============Test Case 6=====================" << endl;
    test_start_no_cycle();
    cout << "===============Test Case 7=====================" << endl;
    test_intersection_cycle_before();
    cout << "===============Test Case 9=====================" << endl;
    test_intersection_cycle_after();
    cout << "===============Test Case 9=====================" << endl;
    test_no_intersection_one_cycle_one_not();

    return 0;

}

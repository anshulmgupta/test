#include <iostream>
#include <map>
#include <vector>
#include <climits>
using namespace std;
struct Node{
    int data;
    int ref_count;
    Node *next;
    Node *prev;
    Node(int data): data(data), ref_count(1), next(nullptr), prev(nullptr){}
};

class DataStructure{
    using Snapshot = map<int, Node*>;
    map<int, vector<Node*>> data_map;
    Node *head;

    void add_to_list(Node *data){
        if(head == nullptr){
            head = data;
            return;
        }
        data->next = head;
        head->prev = data;
        head = data;
    }

    void _delete(Node *data){
        if(--data->ref_count == 0){
            // Handle Head Node case
            if(data == head){
                head = head->next;
                data->next->prev = nullptr;
                data->next = nullptr;
                delete data;
            }
            // Handles last node in the list
            else if(data->next == nullptr){
                data->prev->next = data->next;
                data->prev = nullptr;
                delete data;
            }
            // Handles any middle node
            else{
                data->prev->next = data->next;
                data->next->prev = data->prev;
                delete data;
            }
        }
    }
public:
    DataStructure(): head(nullptr){}
  
    void put(int key, int value){
        Node *tmp = new Node(value);
        data_map[key].push_back(tmp);
        add_to_list(tmp);
    }

    int get(int key){
        if(data_map.find(key)!=data_map.end()){
            Node *tmp = data_map[key].back();
            return tmp->data;
        }
        return INT_MIN;
    }

    void del(int key){
        if(data_map.find(key)!=data_map.end()){
            auto data = data_map[key];
            for(auto d : data){
                _delete(d);
            }
            data_map.erase(key);
        }
    }
  
    Snapshot Take_Snapshot(){
        Snapshot s_shot;
        for(auto const &d : data_map){
            (d.second.back())->ref_count++;
            s_shot[d.first] = d.second.back();
        }
        return s_shot;
    }
  
    int get(int key, Snapshot& snap_shot){
        if(snap_shot.find(key)!=snap_shot.end()){
            Node *tmp = snap_shot[key];
            return tmp->data;
        }
        return INT_MIN;
    }
  
    void del_snapshot(Snapshot& snap_shot){
        for(auto d : snap_shot){
            _delete(d.second);
            snap_shot.erase(d.first);
        }
    }
};
int main(){
    DataStructure ds;
    ds.put(1,2);
    ds.put(2,4);
    ds.put(3,7);
    ds.del(3);
    ds.put(4,70);
    ds.del(1);
    ds.put(5,78);
    ds.del(2);
    ds.put(78,70);
    ds.put(2,4);
    cout << ds.get(2) << endl;
    /*
    cout << ds.get(2) << endl;
    auto res = ds.Take_Snapshot();
    cout << ds.get(2, res) << endl;
    ds.put(2,6);
    cout << ds.get(2) << endl;
    cout << ds.get(2, res) << endl;
    ds.del_snapshot(res);
    cout << ds.get(2, res) << endl;
    */
}

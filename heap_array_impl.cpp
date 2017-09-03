#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Heap {

private:
    int __size;
    int __capacity;
    vector<int> _arr;
public:
    Heap(vector<int> &arr) : _arr{arr},
                             __size(arr.size()),
                             __capacity(arr.size())
                             {}

    Heap(int size): __size(0),
                    __capacity(size),
                    _arr(size) {}

    void build_heap(){
        
        for(int i = (__size-2/2); i >= 0; i--){
            min_heapify(i);
        }
    }

    void min_heapify(int idx){
        int left = left_child(idx);
        int right = right_child(idx);
        int smaller = idx;

        if(left < __size && _arr[left] < _arr[smaller])
            smaller = left;

        if(right < __size && _arr[right] < _arr[smaller])
            smaller = right;
  
        if(smaller != idx){
            swap(_arr[idx], _arr[smaller]);
            min_heapify(smaller);
        }
    }

    int peek_top(){
        return _arr[0];
    }

    void print_heap_arr(){
        cout << endl;
        for_each(_arr.begin(), _arr.end(), [](int i){cout << i << ",";});
        cout << endl;
    }
 
    void print_heap(){
        int sz = 0;
        while(sz != __size){
            cout << _arr[sz] << ",";
            sz++;
        }
        cout << endl;
    }

    int pop(){
       if(__size <= 0){
           cout << "HEAP IS EMPTY!!!" << endl;
           return INT_MIN;
       }
       int val = _arr[0];
       if(__size > 1){
           _arr[0] = _arr[__size-1];
           __size--;
           min_heapify(0);
       }
       return val;
    }

    void push(int val){
        if(__size >= __capacity){
            cout << "HEAP IF FULL!!!" << endl;
            return;
        }
      
        __size++;
        int idx = __size-1;
        _arr[idx] = val;
        while(idx != 0 && _arr[parent(idx)] > _arr[idx]){
            swap(_arr[parent(idx)], _arr[idx]);
            idx = parent(idx);
        }
    }

    void increase_key(int val, int idx){
        if(idx + 1 >= __size){
            cout << "Index is out of range!!!" << endl;
            return;
        }
        _arr[idx] = val;        
        min_heapify(idx);
    }

    void decrease_key(int val, int idx){
        if(idx + 1 >= __size){
            cout << "Index is out of range!!!" << endl;
            return;
        }
        _arr[idx] = val;
        while(idx != 0 && _arr[parent(idx)] > _arr[idx]){
            swap(_arr[parent(idx)], _arr[idx]);
            idx = parent(idx);
        }
    }
  
    void sort(){
        for(int i = __size - 1; i >= 0; i--){
            swap(_arr[0], _arr[i]);
            __size--;
            min_heapify(0);
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

int main(){

    vector<int> arr{4,1,3,2,16,9,10,14,8,7};
    Heap hp(arr);
    hp.build_heap();
    for_each(arr.begin(), arr.end(), [](int i){cout << i << ",";});
    //hp.sort();
    hp.print_heap_arr();
    cout << endl << "---HEAP---" << endl;
    hp.print_heap();
    cout << hp.pop() << endl;
    cout << hp.pop() << endl;
    cout << hp.pop() << endl;
    cout << endl << "---HEAP---" << endl;
    hp.print_heap();
    hp.push(1);
    cout << endl << "---HEAP---" << endl;
    hp.print_heap();
    hp.increase_key(17,2);
    cout << endl << "---HEAP---" << endl;
    hp.print_heap();
    hp.decrease_key(9,2);
    cout << endl << "---HEAP---" << endl;
    hp.print_heap();

    Heap hp1(10);
    hp1.push(3);
    hp1.push(2);
    hp1.push(1);
    hp1.push(15);
    hp1.push(5);
    hp1.push(4);
    hp1.push(45);
    cout << endl << "---HEAP---" << endl;
    hp1.print_heap();
    return 0;

}

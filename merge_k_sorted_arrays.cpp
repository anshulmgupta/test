#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct HeapNode{
    int val;
    int i;
    int j;
};

class Heap {

private:
    int __size;
    int __capacity;
    vector<HeapNode> _arr;
public:

    Heap(int size): __size(0),
                    __capacity(size),
                    _arr(size) {}

    void min_heapify(int idx){
        int left = left_child(idx);
        int right = right_child(idx);
        int smaller = idx;

        if(left < __size && _arr[left].val < _arr[smaller].val)
            smaller = left;

        if(right < __size && _arr[right].val < _arr[smaller].val)
            smaller = right;
  
        if(smaller != idx){
            swap(_arr[idx], _arr[smaller]);
            min_heapify(smaller);
        }
    }

    int peek_top(){
        return _arr[0].val;
    }

    void print_heap(){
        int sz = 0;
        while(sz != __size){
            cout << _arr[sz].val << ",";
            sz++;
        }
        cout << endl;
    }

    HeapNode pop(){
       if(__size <= 0){
           cout << "HEAP IS EMPTY!!!" << endl;
           HeapNode hnode = {INT_MIN, -1, -1};
           return hnode;
       }
       auto val = _arr[0];
       if(__size > 1){
           _arr[0] = _arr[__size-1];
           __size--;
           min_heapify(0);
       }
       return val;
    }

    void push(HeapNode h_node){
        if(__size >= __capacity){
            cout << "HEAP IF FULL!!!" << endl;
            return;
        }
      
        __size++;
        int idx = __size-1;
        _arr[idx] = h_node;
        while(idx != 0 && _arr[parent(idx)].val > _arr[idx].val){
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

int main(){
   vector< vector<int> > arr = {{2, 6, 12, 34},
                                {1, 9, 20, 1000},
                                {23, 34, 90, 2000}
                               };
   int k = arr.size();
   int n = arr[0].size();
   Heap my_heap(k);
   vector<int> output;

   for(int i = 0; i < k; i++){
       HeapNode my_node;
       my_node.val = arr[i][0];
       my_node.i = i;
       my_node.j = 0;
       my_heap.push(my_node);
   }

   for(int i = 0; i < n*k; i++){
       auto d = my_heap.pop();
       output.push_back(d.val);
  
       if(d.j+1 < n){
           int v = arr[d.i][d.j+1];
           d.val = v;
           d.j = d.j+1;
           my_heap.push(d);
       }
   }

   for_each(output.begin(), output.end(), [](int i){ cout << i << ",";  });
   cout << endl;
   return 0;

}

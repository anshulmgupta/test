#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <set>
using namespace std;

struct HeapNode{
    int dist;
    int vertex;
    HeapNode(int dist, int vertex): dist(dist), vertex(vertex){}
};

class Heap {
    int size;
    int capacity;
    vector<HeapNode*> arr;
    map<int, int> heap_data_set;

    int left_child(int idx){
        return 2*idx + 1;
    }
   
    int right_child(int idx){
        return 2*idx + 2;
    }

    int parent(int idx){
        return (idx-1)/2;
    }

    void min_heapify(int idx){
        int left = left_child(idx);
        int right = right_child(idx);
        int smaller = idx;

        if(left < size && arr[left]->dist < arr[smaller]->dist)
            smaller = left;

        if(right < size && arr[right]->dist < arr[smaller]->dist)
            smaller = right;

        if(smaller != idx){
            swap(arr[idx], arr[smaller]);
            heap_data_set[arr[idx]->vertex] = idx;
            heap_data_set[arr[smaller]->vertex] = smaller;
            min_heapify(smaller);
        }
    }

public:
    Heap(int capacity): size(0), capacity(capacity), arr(capacity){}

    void insert(HeapNode *data){
        if(size > capacity){
            cout << "HEAP FULL!!!" << endl;
            return;
        }

        size++;
        int idx = size-1;
        int prnt = parent(idx);
        arr[idx] = data;
        heap_data_set[data->vertex] = idx;

        while(idx != 0 && arr[idx]->dist < arr[prnt]->dist){
            swap(arr[idx], arr[prnt]);
            heap_data_set[arr[idx]->vertex] = idx;
            heap_data_set[arr[prnt]->vertex] = prnt;
            idx = parent(idx);
            prnt = parent(idx);
        }
    }

    HeapNode* extract_min(){
        if(size <= 0){
            cout << "HEAP IS EMPTY" << endl;
            return nullptr;
        }
    
        HeapNode* tmp = arr[0];
        heap_data_set.erase(tmp->vertex);
        if(size >= 1){
           arr[0] = arr[size-1];
           heap_data_set[arr[0]->vertex] = 0;
           size--;
           min_heapify(0);
        }
        return tmp;
    }

    void decrease_key(int vertex, int dist){
        if(heap_data_set.find(vertex) == heap_data_set.end())
            return;

        int idx = heap_data_set[vertex];
        arr[idx]->dist = dist;
        int prnt = parent(idx);
       
        while(idx != 0 && arr[idx]->dist < arr[prnt]->dist){
            swap(arr[idx], arr[prnt]);
            heap_data_set[arr[idx]->vertex] = idx;
            heap_data_set[arr[prnt]->vertex] = prnt;
            idx = parent(idx);
            prnt = parent(idx);
        }
    }

    bool is_in_heap(int data){
        if(heap_data_set.find(data) != heap_data_set.end())
            return true;
        return false;
    }

    HeapNode* top(){
        return arr[0];
    }

    int get_dist(int vertex){
        int idx = heap_data_set[vertex];
        HeapNode *tmp = arr[idx];
        return tmp->dist;
    }

    bool is_empty(){
        return size == 0;
    }
};

class UnDirectedGraph {
    int no_vertex;
    map<int, vector< pair<int, int> > > graph;
    set<int> vertices;
public:
    UnDirectedGraph(int no_vertex): no_vertex(no_vertex){}

    void add_edge(int src, int dst, int dist){
        graph[src].push_back({dst, dist});
        graph[dst].push_back({src, dist});
        vertices.insert(src);
        vertices.insert(dst);
    }

    map<int, int> find_shortest_path(int source){
        map<int, int> dist;
        Heap hp(no_vertex);
        for(auto vertex : vertices){
            dist[vertex] = INT_MAX;
            HeapNode *node = new HeapNode(INT_MAX, vertex);
            hp.insert(node);
        }
        dist[source] = 0;
        hp.decrease_key(source, 0);
        while(!hp.is_empty()){
   
            HeapNode *u = hp.extract_min();
            
            for(auto child : graph[u->vertex]){
                if(hp.is_in_heap(child.first) && dist[u->vertex] != INT_MAX && dist[child.first] > dist[u->vertex] + child.second){
                    dist[child.first] = dist[u->vertex] + child.second;
                    hp.decrease_key(child.first, dist[child.first]);
                }
            }
        }
        return dist;
    }
};

class DirectedGraph {
    int no_vertex;
    map<int, vector< pair<int, int> > > graph;
    set<int> vertices;
public:
    DirectedGraph(int no_vertex): no_vertex(no_vertex){}

    void add_edge(int src, int dst, int dist){
        graph[src].push_back({dst, dist});
        vertices.insert(src);
        vertices.insert(dst);
    }

    map<int, int> find_shortest_path(int source){
        map<int, int> dist;
        Heap hp(no_vertex);
        for(auto vertex : vertices){
            dist[vertex] = INT_MAX;
            HeapNode *node = new HeapNode(INT_MAX, vertex);
            hp.insert(node);
        }
        dist[source] = 0;
        hp.decrease_key(source, 0);
        while(!hp.is_empty()){

            HeapNode *u = hp.extract_min();

            for(auto child : graph[u->vertex]){
                if(hp.is_in_heap(child.first) && dist[u->vertex] != INT_MAX && dist[child.first] > dist[u->vertex] + child.second){
                    dist[child.first] = dist[u->vertex] + child.second;
                    hp.decrease_key(child.first, dist[child.first]);
                }
            }
        }
        return dist;
    }
};

void test_case_one(){
    UnDirectedGraph dgp(9);
    dgp.add_edge(0, 1, 4);
    dgp.add_edge(0, 7, 8);
    dgp.add_edge(1, 2, 8);
    dgp.add_edge(1, 7, 11);
    dgp.add_edge(2, 3, 7);
    dgp.add_edge(2, 8, 2);
    dgp.add_edge(2, 5, 4);
    dgp.add_edge(3, 4, 9);
    dgp.add_edge(3, 5, 14);
    dgp.add_edge(4, 5, 10);
    dgp.add_edge(5, 6, 2);
    dgp.add_edge(6, 7, 1);
    dgp.add_edge(6, 8, 6);
    dgp.add_edge(7, 8, 7);
    int src_vertex = 0;
    auto result = dgp.find_shortest_path(src_vertex);
    for(auto d : result){
        cout << "Vertex = " << d.first << " Distance =  " << d.second << endl;
    }
    cout << endl;
}

void test_case_two(){
    DirectedGraph dgp(5);
    dgp.add_edge(1 ,2 ,10);
    dgp.add_edge(1 ,4 ,5);
    dgp.add_edge(2 ,3 ,1);
    dgp.add_edge(2 ,4 ,3);
    dgp.add_edge(3 ,5 ,6);
    dgp.add_edge(4 ,2 ,2);
    dgp.add_edge(4 ,3 ,9);
    dgp.add_edge(4 ,5 ,2);
    dgp.add_edge(5 ,1 ,7);
    dgp.add_edge(5 ,3 ,4);
    int src_vertex = 1;
    auto result = dgp.find_shortest_path(src_vertex);
    for(auto d : result){
        cout << "Vertex = " << d.first << " Distance =  " << d.second << endl;
    }
    cout << endl;
}

void test_case_three(){
    DirectedGraph dgp(6);
    dgp.add_edge(1 ,6 ,14);
    dgp.add_edge(1 ,3 ,9);
    dgp.add_edge(1 ,2 ,7);
    dgp.add_edge(2 ,3 ,10);
    dgp.add_edge(2 ,4 ,15);
    dgp.add_edge(3 ,6 ,2);
    dgp.add_edge(3 ,4 ,11);
    dgp.add_edge(4 ,5 ,6);
    dgp.add_edge(6 ,5 ,9);
    int src_vertex = 1;
    auto result = dgp.find_shortest_path(src_vertex);
    for(auto d : result){
        cout << "Vertex = " << d.first << " Distance =  " << d.second << endl;
    }
    cout << endl;


}

int main(){
    test_case_one();
    test_case_two();
    test_case_three();
    return 0;
}

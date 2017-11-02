#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <climits>
#include <algorithm>
using namespace std;

class UndirectedGraph{
    int no_vertices;
    map<int, vector<int>> graph;
public:
    UndirectedGraph(int vertices): no_vertices(vertices) {}

    void add_edge(int v, int u){
        graph[v].push_back(u);
        //graph[u].push_back(v);
    }

    void BFS(int start){
        queue<int> q;
        set<int> visited;
        q.push(start);
        visited.insert(start);
        while(!q.empty()){
            auto d = q.front();
            q.pop();
            cout << d << ",";
            for(auto child : graph[d]){
                if(visited.find(child) == visited.end()){
                    visited.insert(child);
                    q.push(child);
                }
            }
        }
        cout << endl;
    }
    
    void do_dfs(int vertex, set<int> &visited){
        cout << vertex << ",";
        for(auto child: graph[vertex]){
            if(visited.find(child) == visited.end()){
                visited.insert(child);
                do_dfs(child, visited);
            }
        }
    }

    void DFS(int start){
        set<int> visited;
        visited.insert(start);
        do_dfs(start, visited);
        cout << endl;
    }

    void shortest_path(int src, int dst){
        queue<int> q;
        q.push(src);
        map<int, int> pred;
        pred[src] = INT_MIN;
        while(!q.empty()){
            auto d = q.front();
            q.pop();
            if(d == dst)
                break;
            for(auto child : graph[d]){
                if(pred.find(child) == pred.end()){
                    pred[child] = d;
                    q.push(child);
                }
            }
        }
        int curr = dst;
        vector<int> path;
        while(curr != INT_MIN){
            path.insert(path.begin(), curr);
            curr = pred[curr];
        }
        for(auto d: path){
            cout << d << "->";
        }
        cout << endl;
    }
};


struct Edge{
    string src;
    string dst;
    int cost;
public:
    void print(){
        cout << "SRC = " << src << " DST = " << dst << " COST =  " << cost << endl;
    }
};

struct Node{
    string city;
    Node *parent;
    int rank;
    Node(string city): city(city), parent(this), rank(0){}
};

struct Result{
    vector<Edge> edges;
    int min_cost;
};

class Kruskal{
    int no_vertex;
    vector<Edge> edges;
    map<string, Node*> set;
    void make_set(){
        for(auto const &edge : edges){
            if(set.find(edge.src) == set.end()){
                set[edge.src] = new Node(edge.src);
            }
            if(set.find(edge.dst) == set.end()){
                set[edge.dst] = new Node(edge.dst);
            }
        }
    }

    Node *find_parent(Node *node){
        Node *parent = node->parent;
        if(parent == node)
            return node;
        node->parent = find_parent(node->parent);
        return node->parent;
    }

    bool union_find(string src, string dst){
        Node *parent_src = find_parent(set[src]);
        Node *parent_dst = find_parent(set[dst]);
        if(parent_src == parent_dst)
            return false;
        if(parent_src->rank > parent_dst->rank){
            parent_dst->parent = parent_src;
        }
        else if(parent_src->rank < parent_dst->rank){
            parent_src->parent = parent_dst;
        }
        else{
            parent_dst->parent = parent_src;
            parent_src->rank++;
        }
        return true;
    }
public:   
    Kruskal(int no_vertex, vector<Edge> &edges): no_vertex(no_vertex), edges(edges){}
    
    Result find_mst(){
        make_set();
        sort(edges.begin(), edges.end(), [&](Edge a, Edge b){ return a.cost < b.cost; });
        int min_cost = 0;
        vector<Edge> result;
        for(auto const &edge : edges){
            if(union_find(edge.src, edge.dst)){
                result.push_back(edge);
                min_cost += edge.cost;
            }
        }
        return {result, min_cost};
    }
};

void test_kruskal(){
    vector<Edge> edges = {{"S", "A", 7},
                          {"S", "C", 8},
                          {"A", "C", 3},
                          {"A", "B", 6},
                          {"C", "B", 4},
                          {"C", "D", 3},
                          {"B", "D", 2},
                          {"B", "T", 5},
                          {"D", "T", 2}};
    int no_vertex = 6;
    Kruskal krskl(no_vertex, edges);
    auto res = krskl.find_mst();
    cout << "Total Min Cost = " << res.min_cost << endl;
    for(auto &edge : res.edges){
        edge.print();
        cout << endl;
    }
}


void test_bfs_dfs(){
    UndirectedGraph ug(4);
    ug.add_edge(0, 1);
    ug.add_edge(0, 2);
    ug.add_edge(1, 2);
    ug.add_edge(2, 0);
    ug.add_edge(2, 3);
    ug.add_edge(3, 3);
    ug.BFS(2);
    ug.DFS(2);
}

void test_shortest_path(){
    UndirectedGraph ug(10);
    ug.add_edge(0, 8);
    ug.add_edge(1, 3);
    ug.add_edge(1, 7);
    ug.add_edge(1, 9);
    ug.add_edge(1, 2);
    ug.add_edge(2, 8);
    ug.add_edge(2, 1);
    ug.add_edge(2, 4);
    ug.add_edge(3, 4);
    ug.add_edge(3, 5);
    ug.add_edge(3, 1);
    ug.add_edge(4, 2);
    ug.add_edge(4, 3);
    ug.add_edge(5, 3);
    ug.add_edge(5, 6);
    ug.add_edge(6, 7);
    ug.add_edge(6, 5);
    ug.add_edge(7, 1);
    ug.add_edge(7, 6);
    ug.add_edge(8, 2);
    ug.add_edge(8, 0);
    ug.add_edge(8, 9);
    ug.add_edge(9, 1);
    ug.add_edge(9, 8);
    ug.shortest_path(0, 4);
}

int main(){
    test_bfs_dfs();
    test_shortest_path();
    cout << endl;
    test_kruskal();
}

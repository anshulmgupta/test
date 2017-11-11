#include <iostream>
#include <vector>

using namespace std;

struct Interval{
    int start;
    int end;
};

struct Node{
    Interval interval;
    int max;
    Node *left;
    Node *right;
    Node(Interval i): interval(i), max(i.end), left(nullptr), right(nullptr){}
};

class IntervalTree{
    Node *root;

    bool is_overlapping(Interval a, Interval b){
        if(a.start <= b.end && b.start <= a.end)
            return true;
        return false;
    }

public:
    IntervalTree(): root(nullptr){}

    Node *_insert(Node *curr, Interval i){
        if(curr == nullptr){
            return new Node(i);
        }
        if(i.start < curr->interval.start)
            curr->left = _insert(curr->left, i);
        else
            curr->right = _insert(curr->right, i);

        if(curr->max < i.end)
            curr->max = i.end;

        return curr;
    }

    void insert(Interval i){
        root = _insert(root, i);
    }

    void _print(Node *root){
        if(root == nullptr)
            return;
        _print(root->left);
        cout << root->interval.start << "," << root->interval.end << "," << root->max << endl;
        _print(root->right);
    }

    void print(){
        _print(root);
    }

    Interval _search_overlapping(Node *root, Interval i){

        if(root == nullptr)
            return {};

        if(is_overlapping(root->interval, i))
            return root->interval;

        if(root->left && i.start <= root->left->max)
            return _search_overlapping(root->left, i);

        return _search_overlapping(root->right, i);
    }

    Interval search_overlapping(Interval i){
        Node *curr = root;
        return _search_overlapping(curr, i);
    }
};

int main(){
    vector<Interval> intervals = {{15, 20}, {10, 30}, {17, 19},
                                  {5, 20}, {12, 15}, {30, 40}};

    IntervalTree it;
    for(auto interval : intervals){
        it.insert(interval);
    }
    it.print();
    auto res = it.search_overlapping({6,7});
    cout << res.start << "," << res.end << endl;
}

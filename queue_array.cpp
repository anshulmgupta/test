#include <iostream>
#include <climits>
using namespace std;

class Queue{

public:
    Queue(int size): _size(size),
                     _que(new int[size]),
                     _front(-1),
                     _back(-1),
                     _cnt(0){}

    void push(int val){
        if(isFull()){
            cout << "Queue is Full" << endl;
            return;
        }
        _back = (_back+1)%_size;
        _que[_back] = val;
        _cnt++;
    }
   
    void pop(){
        if(isEmpty()){
            cout << "Queue is Empty" << endl;
            return;
        }
        _front = (_front+1)%_size;
        _cnt--;
    }

    int front(){
        if(!isEmpty()){
            int tmp = (_front+1)%_size;
            return _que[tmp];
        }
        return INT_MIN;
    }

    bool isFull() { return _cnt == _size; }

    int size() const { return _cnt; }

    bool isEmpty() { return _cnt == 0; }

    void print_queue(){
        if(isEmpty()){
            cout << "Queue is Empty" << endl;
            return;
        }
        if(_back >= _front){
            for(int i = _front ; i <= _back ; i++){
                cout << _que[i] << " -> ";
            }
        }
        else{
            for(int i = _front ; i < _size ; i++){
                cout << _que[i] << " -> ";
            }
            for(int i = 0 ; i <= _back ; i++){
                cout << _que[i] << " -> ";
            }
        }

    }

private:
    int _size;
    int *_que;
    int _front;
    int _back;
    int _cnt;

};


int main(){

    Queue q(4);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout << q.front() << endl;
    q.pop();
    q.push(6);
    q.pop();
    cout << q.front() << endl;
    q.print_queue();
    return 0;

}

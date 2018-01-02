#include <iostream>
#include <climits>
#include <stack>

using namespace std;

class MinStack {
    int curr_min;
    stack<int> min_st;
public:
    void push(int val){
        if(min_st.empty()){
            min_st.push(val);
            curr_min = val;
        }
        else if(val > curr_min)
            min_st.push(val);
        else{
            min_st.push(val - curr_min);
            curr_min = val;
        }
    }

    int pop(){
        int data = min_st.top();
        min_st.pop();
        if(data <= curr_min){
            int tmp = curr_min; 
            curr_min = tmp - data;
            return tmp;
        }
        else
            return data;
    }

    int get_min(){
        return curr_min;
    }
};

void test_case_one(){
    MinStack ms;
    ms.push(10);
    ms.push(20);
    ms.push(5);
    ms.push(15);
    ms.push(3);
    ms.push(6);
    ms.push(2);
    ms.push(1);
    cout << ms.get_min() << endl;
    cout << "Element : " << ms.pop() << endl;
    cout << ms.get_min() << endl;
    cout << "Element : " << ms.pop() << endl;
    cout << ms.get_min() << endl;
    cout << "Element : " << ms.pop() << endl;
    cout << ms.get_min() << endl;
    cout << "Element : " << ms.pop() << endl;
    cout << ms.get_min() << endl;
    cout << "Element : " << ms.pop() << endl;
    cout << ms.get_min() << endl;
    cout << "Element : " << ms.pop() << endl;
    cout << ms.get_min() << endl;
    cout << "Element : " << ms.pop() << endl;
    cout << ms.get_min() << endl;
    cout << "Element : " << ms.pop() << endl;
}

int main(){
    test_case_one();
    return 0;
}

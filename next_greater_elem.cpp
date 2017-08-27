#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void next_greater_elem(vector<int> &arr){

    stack<int> st;
    for(auto num : arr){
        while(!st.empty() && num > st.top()){
            auto n = st.top();
            cout << n << " ----> " << num << endl;
            st.pop();
        }
        st.push(num);
    }

    while(!st.empty()){
        auto n = st.top();
        cout << n << " ----> " << -1 << endl;
        st.pop();
    } 

}


int main(){

    vector<int> arr{11, 13, 21, 3};
    next_greater_elem(arr);
    cout << "#######################" << endl;
    arr = {4, 5, 2, 25};
    next_greater_elem(arr);
    cout << "#######################" << endl;
    arr = {13, 7, 6, 12};
    next_greater_elem(arr);
    cout << "#######################" << endl;
    return 0;

}

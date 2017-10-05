#include <iostream>
#include <vector>
using namespace std;


void print_string(int n, int idx, string str){
    if(n == idx){
        cout << str << endl;
        return;
    }
    str.push_back('0');
    print_string(n, idx+1, str);
    str.pop_back();
    str.push_back('1');
    print_string(n, idx+1, str);
    str.pop_back();
}

void print_string_one(int n, int idx, vector<char> str){
    if(n == idx){
        for(auto d: str)
            cout << d;
        cout << endl;
        return;
    }
    str[idx] = '0';
    print_string_one(n, idx+1, str);
    str[idx] = '1';
    print_string_one(n, idx+1, str);
}

void test_case_one(){
    int no_bits = 3;
    print_string(no_bits, 0, "");
}

void test_case_two(){
    int no_bits = 3;
    vector<char> str(no_bits);
    print_string_one(no_bits, 0, str);
}

int main(){
    test_case_one();
    cout << "Test Case 2" << endl;
    test_case_two();
}

#include <iostream>

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

void test_case_one(){
    int no_bits = 3;
    print_string(no_bits, 0, "");
}

int main(){
    test_case_one();
}

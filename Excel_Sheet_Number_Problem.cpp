#include <iostream>
using namespace std;
int main() {
    string result;
    int n;
    cout << "Enter Number = ";
    cin >> n;
    while(n > 0){
        n = n-1;
        int rem = n % 26;
        char tmp = 'A' + rem;
        result =  tmp + result;
        n /= 26;
    }
    cout << "Excel = " << result << endl;
    int number = 0;
    for(auto ch : result){
        number = number * 26 + ch-'A' + 1;
    }
    cout << "Number = " << number << endl;
 
}

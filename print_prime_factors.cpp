#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void print_factors(string str, int first, int num){

    for(int i = 2; i <= sqrt(num); i++){
        if(num%i == 0){
            if(i >= first && num/i >= i){
                string factor;
                factor = str + to_string(i) + " * " + to_string(num/i);
                cout << factor << endl;
                print_factors(str + to_string(i) + " * ", i, num/i);
            }
        }
    }

}

int main(){

    cout << "Enter the Number : ";
    int num;
    cin >> num;
    cout << 1 << " * " << num << endl;
    print_factors("", 1, num);

}

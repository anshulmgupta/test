#include <iostream>
#include <cmath>
using namespace std;

double sqrt(int number){
    double start = 0;
    double end = number;
    double prev_mid = 0;
    double precision = 0.0005;
    double mid = start + (end-start)/2;
    double diff = fabs(mid - prev_mid);
    while(mid*mid != number && diff > precision){
        if(mid*mid > number)
            end = mid;
        else
            start = mid;
        prev_mid = mid;
        mid = start + (end-start)/2;
        diff = fabs(mid - prev_mid);
    }
    return mid;
}

void test_case_one(){
    int num = 2;
    double result = sqrt(2);
    cout << "Sqrt of 2 = " << result << endl;
}

void test_case_two(){
    int num = 16;
    double result = sqrt(16);
    cout << "Sqrt of 16 = " << result << endl;
}

int main(){
    test_case_one();
    test_case_two();
    return 0;
}

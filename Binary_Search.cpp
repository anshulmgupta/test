#include <iostream>
#include <vector>
using namespace std;

int find_ceil(vector<int> &arr, int key){
    int start = 0;
    int end = arr.size()-1;
    while(start <= end){
        int mid = (start + end)/2;
        if(arr[mid] == key)
            return arr[mid];
        else if(key > arr[mid])
            start = mid+1;
        else
            end = mid-1;
    }
    if(start >= 0 && start < arr.size())
        return arr[start];
    return -1;
}

int find_floor(vector<int> &arr, int key){
    int start = 0;
    int end = arr.size()-1;
    while(start <= end){
        int mid = (start + end)/2;
        if(arr[mid] == key)
            return arr[mid];
        else if(key > arr[mid])
            start = mid+1;
        else
            end = mid-1;
    }
    if(end >=0 && end < arr.size())
        return arr[end];
    return -1;
}

void test_case_one(){
    vector<int> arr = {1, 2, 8, 10, 10, 12, 19};
    int key = 5;
    int res = find_ceil(arr, key);
    cout << "Ceil of 5 = " << res << endl;
}

void test_case_two(){
    vector<int> arr = {1, 2, 8, 10, 10, 12, 19};
    int key = 20;
    int res = find_ceil(arr, key);
    cout << "Ceil of 20 = " << res << endl;
}

void test_case_three(){
    vector<int> arr = {1, 2, 8, 10, 10, 12, 19};
    int key = 0;
    int res = find_ceil(arr, key);
    cout << "Ceil of 0 = " << res << endl;
}

void test_case_four(){
    vector<int> arr = {1, 2, 8, 10, 10, 12, 19};
    int key = 5;
    int res = find_floor(arr, key);
    cout << "Floor of 5 = " << res << endl;
}

void test_case_five(){
    vector<int> arr = {1, 2, 8, 10, 10, 12, 19};
    int key = 20;
    int res = find_floor(arr, key);
    cout << "Floor of 20 = " << res << endl;
}

void test_case_six(){
    vector<int> arr = {1, 2, 8, 10, 10, 12, 19};
    int key = 0;
    int res = find_floor(arr, key);
    cout << "Floor of 0 = " << res << endl;
}

void test_case_seven(){
    vector<int> arr = {1, 2, 8, 10, 10, 12, 19};
    int key = 11;
    int res = find_floor(arr, key);
    cout << "Floor of 11 = " << res << endl;
}

int main(){
    test_case_one();
    test_case_two();
    test_case_three();
    test_case_four();
    test_case_five();
    test_case_six();
    test_case_seven();
    return 0;
}

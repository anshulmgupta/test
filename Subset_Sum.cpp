#include <iostream>
#include <vector>
using namespace std;

void subset_sum(vector<int> arr, vector<int> result, int target, int idx, int sum){

    if(sum == target){
        for(auto d: result)
            cout << d << ",";
        cout << endl;
        return;
    }
    for(int i = idx; i<arr.size();i++){
        if(sum + arr[i] <= target){
            result.push_back(arr[i]);
            subset_sum(arr, result, target, i+1, sum+arr[i]);
            result.pop_back();
        }
    }
}

void test_case_one(){
    vector<int> arr = {1,4,5,6};
    vector<int> result;
    int target = 6;
    subset_sum(arr, result, target, 0, 0);
}

void test_case_two(){
    vector<int> arr = {10, 7, 5, 18, 12, 20, 15};
    vector<int> result;
    int target = 35;
    subset_sum(arr, result, target, 0, 0);
}

int main(){
    test_case_one();
    cout <<  "=============================" << endl;
    test_case_two();
    return 0;
}

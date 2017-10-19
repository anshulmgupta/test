#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Max_Value{
    int max_val;
    int start;
    int end;
};

Max_Value find_cross_sum(vector<int> &arr, int start, int mid, int end){
    int s = 0;
    int e = 0;
    int left_sum = INT_MIN;
    int curr_sum=0;
    for(int i=mid; i>=start;i--){
        curr_sum += arr[i];
        if(curr_sum > left_sum){
            left_sum = curr_sum;
            s = i;
        }
    }

    curr_sum = 0;
    int right_sum = INT_MIN;
    for(int i=mid+1;i<=end;i++){
        curr_sum += arr[i];
        if(curr_sum > right_sum){
            right_sum = curr_sum;
            e = i;
        }
    }
    return {left_sum + right_sum, s, e};
}

Max_Value max_val(Max_Value left, Max_Value right, Max_Value cross){
    Max_Value res;
    if(left.max_val > right.max_val)
        res = left;
    else
        res = right;
    if(res.max_val > cross.max_val)
        return res;
    else
        return cross;
}

Max_Value find_max_sum_sub_array(vector<int> &arr, int start, int end){
    if(start == end)
        return {arr[start], start, end};

    int mid = (start + end)/2;
    auto left = find_max_sum_sub_array(arr, start, mid);
    auto right = find_max_sum_sub_array(arr, mid+1, end);
    auto cross = find_cross_sum(arr, start, mid, end);
    return max_val(left, right, cross);
}

Max_Value find_max_kadane(vector<int> &arr){
    int start = 0, end = 0;
    int s = 0;
    int curr_sum = 0;
    int max_sum = INT_MIN;
    for(int i=0;i<arr.size();i++){
        curr_sum += arr[i];

        if(curr_sum > max_sum){
            max_sum = curr_sum;
            start = s;
            end = i;
        }
  
        if(curr_sum < 0){
            curr_sum = 0;
            s = i+1;
        }
    }
    return {max_sum, start, end};
}

void test_case_one(){
    vector<int> arr = {2, 3, 4, 5, 7};
    auto result = find_max_sum_sub_array(arr, 0, arr.size()-1);
    cout << "Max Value = " << result.max_val << endl;
    cout << "Start = " << result.start << endl;
    cout << "End = " << result.end << endl;
}

void test_case_two(){
    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    auto result = find_max_sum_sub_array(arr, 0, arr.size()-1);
    cout << "Max Value = " << result.max_val << endl;
    cout << "Start = " << result.start << endl;
    cout << "End = " << result.end << endl;
}

void test_case_three(){
    vector<int> arr = {2, 3, 4, 5, 7};
    auto result = find_max_kadane(arr);
    cout << "Max Value = " << result.max_val << endl;
    cout << "Start = " << result.start << endl;
    cout << "End = " << result.end << endl;
}

void test_case_four(){
    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    auto result = find_max_kadane(arr);
    cout << "Max Value = " << result.max_val << endl;
    cout << "Start = " << result.start << endl;
    cout << "End = " << result.end << endl;
}

int main(){
    test_case_one();
    test_case_two();
    test_case_three();
    test_case_four();
    return 0;
}

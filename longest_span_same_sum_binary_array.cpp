#include <map>
#include <vector>
#include <iostream>
using namespace std;

int longest_same_sum(vector<int> &arr1, vector<int> &arr2){

    int curr_diff = 0;
    int curr_sum_arr1 = 0;
    int curr_sum_arr2 = 0;
    int max_len=0;
    map<int, int> mp;
    for(int i = 0; i < arr1.size(); i++){
        curr_sum_arr1 += arr1[i];
        curr_sum_arr2 += arr2[i]; 
        curr_diff = curr_sum_arr1 - curr_sum_arr2;
        if(curr_diff == 0){
            max_len = i + 1;
            continue;
        }
        if(mp.find(curr_diff) != mp.end()){
            if(i - mp[curr_diff] > max_len)
                max_len = i - mp[curr_diff];
        }
        else
            mp[curr_diff] = i;
    }

    return max_len;
}

int main(){

    vector<int> arr1{0, 1, 0, 1, 1, 1, 1};
    vector<int> arr2{1, 1, 1, 1, 1, 0, 1};
    cout << "Length of the longest common span with same sum is = " << longest_same_sum(arr1, arr2) << endl;
    
    arr1 = {0, 1, 0, 0, 0, 0};
    arr2 = {1, 0, 1, 0, 0, 1};
    cout << "Length of the longest common span with same sum is = " << longest_same_sum(arr1, arr2) << endl;
    
    arr1 = {0, 1, 0, 1, 1, 1, 1};
    arr2 = {1, 1, 1, 1, 1, 0, 1};
    cout << "Length of the longest common span with same sum is = " << longest_same_sum(arr1, arr2) << endl;

    arr1 = {0, 0, 0};
    arr2 = {1, 1, 1};
    cout << "Length of the longest common span with same sum is = " << longest_same_sum(arr1, arr2) << endl;

    arr1 = {0, 0, 1, 0};
    arr2 = {1, 1, 1, 1};
    cout << "Length of the longest common span with same sum is = " << longest_same_sum(arr1, arr2) << endl;
    return 0;

}

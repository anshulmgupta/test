#include <iostream>
#include <vector>
using namespace std;

double get_median(vector<int>& arr, int start, int end){
    if(start == end)
        return arr[start];
    int no_elems = end - start + 1;
    if(no_elems % 2 != 0)
        return arr[(start + end)/2];
    int mid = (start + end)/2;
    int mid1 = (start + end + 1)/2;
    return (arr[mid] + arr[mid1])/2.0;
}

double find_median_same_length(vector<int>& nums1, vector<int>& nums2, int s1, int e1, int s2, int e2){
    int l1 = e1-s1+1;
    int l2 = e2-s2+1;
    if(l1 < 1 || l2 < 1)
        return 0;
    if(l1 == 1 && l2 == 1)
        return (get_median(nums1, s1, e1) + get_median(nums2, s2, e2))/2.0;
    if(l1 == 2 && l2 ==2){
        int ele1 = max(nums1[s1], nums2[s2]);
        int ele2 = min(nums1[e1], nums2[e2]);
        return (ele1 + ele2)/2.0;
    }
    double mid1 = get_median(nums1, s1, e1);
    double mid2 = get_median(nums2, s2, e2);
    if(mid1 == mid2)
        return mid1;
    if(mid1 < mid2){
        if(l1%2 !=0 && l2%2 != 0){
            int m1 = (s1+e1)/2;
            int m2 = (s2+e2)/2;
            return find_median_same_length(nums1, nums2, m1, e1, s2, m2);
        }
        else{
            int m1 = (s1+e1+1)/2;
            int m2 = (s2+e2+1)/2;
            return find_median_same_length(nums1, nums2, m1, e1, s2, m2-1);
        }
    }
    if(l1%2 !=0 && l2%2 != 0){
        int m1 = (s1+e1)/2;
        int m2 = (s2+e2)/2;
        return find_median_same_length(nums1, nums2, s1, m1, m2, e2);
    }
    else{
        int m1 = (s1+e1+1)/2;
        int m2 = (s2+e2+1)/2;
        return find_median_same_length(nums1, nums2, s1, m1-1, m2, e2);
    }
}

void test_case_one(){
    vector<int> arr1 = {1, 2, 3, 6};
    vector<int> arr2 = {4, 6, 8, 10};
    double median  = find_median_same_length(arr1, arr2, 0, arr1.size()-1, 0, arr2.size()-1);
    cout << "Median of {1, 2, 3, 6} and {4, 6, 8, 10} = " << median << endl;
}

void test_case_two(){
    vector<int> arr1 = {1, 3, 6};
    vector<int> arr2 = {6, 8, 10};
    double median  = find_median_same_length(arr1, arr2, 0, arr1.size()-1, 0, arr2.size()-1);
    cout << "Median of {1, 3, 6} and {6, 8, 10} = " << median << endl;
}

void test_case_three(){
    vector<int> arr1 = {1, 3, 5, 11, 17};
    vector<int> arr2 = {9, 10, 11, 13, 14};
    double median  = find_median_same_length(arr1, arr2, 0, arr1.size()-1, 0, arr2.size()-1);
    cout << "Median of {1, 3, 5, 11, 17} and {9, 10, 11, 13, 14} = " << median << endl;
}

void test_case_four(){
    vector<int> arr1 = {1, 3};
    vector<int> arr2 = {9, 10};
    double median  = find_median_same_length(arr1, arr2, 0, arr1.size()-1, 0, arr2.size()-1);
    cout << "Median of {1, 3} and {9, 10} = " << median << endl;
}

void test_case_five(){
    vector<int> arr1 = {1};
    vector<int> arr2 = {9};
    double median  = find_median_same_length(arr1, arr2, 0, arr1.size()-1, 0, arr2.size()-1);
    cout << "Median of {1} and {9} = " << median << endl;
}

void test_case_six(){
    vector<int> arr1 = {};
    vector<int> arr2 = {};
    double median  = find_median_same_length(arr1, arr2, 0, arr1.size()-1, 0, arr2.size()-1);
    cout << "Median of {} and {} = " << median << endl;
}

int main(){
    test_case_one();
    test_case_two();
    test_case_three();
    test_case_four();
    test_case_five();
    test_case_six();
    return 0;
}

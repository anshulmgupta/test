#include <iostream>

#define NA -1

using namespace std;
// Merge smaller array into bigger array of size 2n
// given both the arrays are sorted.
void merge(int arr1[], int arr2[], int l1, int l2){

    int i = l1-1;
    int j = l2-l1-1;
    int k = l2-1;
    while(i >=0 && j >=0){
        if(arr1[i] > arr2[j]){
            arr2[k--] = arr1[i--];
        }
        else if(arr1[i] < arr2[j]){
            arr2[k--] = arr2[j--];
        }
        else{
            arr2[k--] = arr1[i--];
            arr2[k--] = arr1[j--];
        }
    }
    while(i >= 0){
        arr2[k--] = arr1[i--];
    }
    while(j >= 0)
        arr2[k--] = arr2[j--];
}

void shift_sentinals_back(int arr[], int len){
    int idx = 0;
    for(int i=0;i<len;i++){
        if(arr[i] != NA){
            arr[idx++] = arr[i];
        }
    }
    while(idx < len)
        arr[idx++] = NA;
}

void shift_sentinals_front(int arr[], int len){
    int idx = len-1;
    for(int i = len-1;i>=0;i--){
        if(arr[i] != NA){
            arr[idx--] = arr[i];
        }
    }
    while(idx >=0){
        arr[idx--] = NA;
    }
}

void merge_front(int arr1[], int arr2[], int l1, int l2){
    int i=0;
    int j=l1;
    int k=0;
    while(i < l1 && j < l2){
        if(arr1[i] < arr2[j])
            arr2[k++] = arr1[i++];
        else if(arr1[i] > arr2[j])
            arr2[k++] = arr2[j++];
        else{
            arr2[k++] = arr1[i++];
            arr2[k++] = arr2[j++];
        }
    }
    while(i < l1)
        arr2[k++] = arr1[i++];
    while(j < l2)
        arr2[k++] = arr2[j++];
}

void test_case_one(){
    int arr1[] = {5, 7, 9, 25};
    int arr2[] = {2, 8, 13, 15, 20, 0, 0, 0, 0};
    int len1 = sizeof(arr1)/sizeof(arr1[0]);
    int len2 = sizeof(arr2)/sizeof(arr2[0]);
    merge(arr1, arr2, len1, len2);
    for(auto &d: arr2)
        cout << d << ",";
    cout << endl;
}

void test_case_two(){
    int arr1[] = {4, 6, 8};
    int arr2[] = {1, 9, 10, 0, 0, 0};
    int len1 = sizeof(arr1)/sizeof(arr1[0]);
    int len2 = sizeof(arr2)/sizeof(arr2[0]);
    merge(arr1, arr2, len1, len2);
    for(auto &d: arr2)
        cout << d << ",";
    cout << endl;
}

void test_case_three(){
    int arr1[] = {4, 5, 6};
    int arr2[] = {1, 2, 3, 0, 0, 0};
    int len1 = sizeof(arr1)/sizeof(arr1[0]);
    int len2 = sizeof(arr2)/sizeof(arr2[0]);
    merge(arr1, arr2, len1, len2);
    for(auto &d: arr2)
        cout << d << ",";
    cout << endl;
}

void test_case_four(){
    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5, 6, 0, 0, 0};
    int len1 = sizeof(arr1)/sizeof(arr1[0]);
    int len2 = sizeof(arr2)/sizeof(arr2[0]);
    merge(arr1, arr2, len1, len2);
    for(auto &d: arr2)
        cout << d << ",";
    cout << endl;
}

void test_case_five(){
    int arr1[] = {1, 2, 3};
    int arr2[] = {1, 2, 3, 0, 0, 0};
    int len1 = sizeof(arr1)/sizeof(arr1[0]);
    int len2 = sizeof(arr2)/sizeof(arr2[0]);
    merge(arr1, arr2, len1, len2);
    for(auto &d: arr2)
        cout << d << ",";
    cout << endl;
}

void test_case_six(){
    int arr1[] = {5, 7, 9, 25};
    int arr2[] = {2, 8, NA, NA, NA, 13, NA, 15, 20};
    int len1 = sizeof(arr1)/sizeof(arr1[0]);
    int len2 = sizeof(arr2)/sizeof(arr2[0]);
    shift_sentinals_back(arr2, len2);
    merge(arr1, arr2, len1, len2);
    for(auto &d: arr2)
        cout << d << ",";
    cout << endl;
}

void test_case_seven(){
    int arr1[] = {5, 7, 9, 25};
    int arr2[] = {2, 8, NA, NA, NA, 13, NA, 15, 20};
    int len1 = sizeof(arr1)/sizeof(arr1[0]);
    int len2 = sizeof(arr2)/sizeof(arr2[0]);
    shift_sentinals_front(arr2, len2);
    merge_front(arr1, arr2, len1, len2);
    for(auto &d: arr2)
        cout << d << ",";
    cout << endl;
}

void test_case_eight(){
    int arr1[] = {4, 6, 8};
    int arr2[] = {1, 9, 10, NA, NA, NA};
    int len1 = sizeof(arr1)/sizeof(arr1[0]);
    int len2 = sizeof(arr2)/sizeof(arr2[0]);
    shift_sentinals_front(arr2, len2);
    merge_front(arr1, arr2, len1, len2);
    for(auto &d: arr2)
        cout << d << ",";
    cout << endl;
}

void test_case_nine(){
    int arr1[] = {4, 5, 6};
    int arr2[] = {1, 2, 3, NA, NA, NA};
    int len1 = sizeof(arr1)/sizeof(arr1[0]);
    int len2 = sizeof(arr2)/sizeof(arr2[0]);
    shift_sentinals_front(arr2, len2);
    merge_front(arr1, arr2, len1, len2);
    for(auto &d: arr2)
        cout << d << ",";
    cout << endl;
}

void test_case_ten(){
    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5, 6, NA, NA, NA};
    int len1 = sizeof(arr1)/sizeof(arr1[0]);
    int len2 = sizeof(arr2)/sizeof(arr2[0]);
    shift_sentinals_front(arr2, len2);
    merge_front(arr1, arr2, len1, len2);
    for(auto &d: arr2)
        cout << d << ",";
    cout << endl;
}

void test_case_XI(){
    int arr1[] = {1, 2, 3};
    int arr2[] = {1, 2, 3, NA, NA, NA};
    int len1 = sizeof(arr1)/sizeof(arr1[0]);
    int len2 = sizeof(arr2)/sizeof(arr2[0]);
    shift_sentinals_front(arr2, len2);
    merge_front(arr1, arr2, len1, len2);
    for(auto &d: arr2)
        cout << d << ",";
    cout << endl;
}

int main(){
    test_case_one();    
    test_case_two();
    test_case_three();
    test_case_four();
    test_case_five();
    test_case_six();
    test_case_seven();
    test_case_eight();
    test_case_nine();
    test_case_ten();
    test_case_XI();

    return 0;
}

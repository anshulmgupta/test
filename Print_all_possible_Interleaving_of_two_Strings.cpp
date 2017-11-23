#include <iostream>

using namespace std;

void print_interleves(string &str1, string &str2, int idx1, int idx2, string &result){

    if(result.length() == str1.length() + str2.length()){
        cout << result << endl;
        return;
    }

    if(idx1 < str1.length()){
        result.push_back(str1[idx1]);
        print_interleves(str1, str2, idx1+1, idx2, result);
        result.pop_back();
    }

    if(idx2 < str2.length()){
        result.push_back(str2[idx2]);
        print_interleves(str1, str2, idx1, idx2+1, result);
        result.pop_back();
    }
}

void test_case_one(){
    string str1 = "AB";
    string str2 = "CD";
    string result;
    print_interleves(str1, str2, 0, 0, result);
    cout << "END OF TEST CASE ONE";
    cout << endl;
}

void test_case_two(){
    string str1 = "ABC";
    string str2 = "DE";
    string result;
    print_interleves(str1, str2, 0, 0, result);
    cout << "END OF TEST CASE TWO";
    cout << endl;
}

void test_case_three(){
    string str1 = "";
    string str2 = "CD";
    string result;
    print_interleves(str1, str2, 0, 0, result);
    cout << "END OF TEST CASE THREE";
    cout << endl;
}

void test_case_four(){
    string str1 = "AB";
    string str2 = "";
    string result;
    print_interleves(str1, str2, 0, 0, result);
    cout << "END OF TEST CASE FOUR";
    cout << endl;
}

void test_case_five(){
    string str1 = "";
    string str2 = "";
    string result;
    print_interleves(str1, str2, 0, 0, result);
    cout << "END OF TEST CASE FIVE";
    cout << endl;
}

int main(){
    test_case_one();
    test_case_two();
    test_case_three();
    test_case_four();
    test_case_five();
    return 0;
}

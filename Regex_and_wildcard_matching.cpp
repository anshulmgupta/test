#include <iostream>

using namespace std;

/*
'.' Matches any single character.
'*' Matches zero or more of the preceding element.
*/
bool isMatch(string strText, string strPattern) {
    if(strPattern.empty())
        return strText.empty();

    if(strPattern.length() >=2 && strPattern[1] == '*'){
        bool match = (!strText.empty() && strText[0] == strPattern[0]) || strPattern[0] == '.';
        return (match && isMatch(strText.substr(1), strPattern)) || isMatch(strText, strPattern.substr(2));
    }
    else{
        bool match = (!strText.empty() && strText[0] == strPattern[0]) || strPattern[0] == '.';
        return match && isMatch(strText.substr(1), strPattern.substr(1));
    }

    return false;
}

/*
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
*/
bool wildcard_matching(string s, string p){
    if(p.empty())
        return s.empty();
        
    if(p[0] == '*'){
        if(p.length() >= 2 && s.empty())
            return false;
        return !s.empty() && wildcard_matching(s.substr(1), p) || wildcard_matching(s, p.substr(1));
    }
        
    if(p[0] == '?' || !s.empty() && s[0] == p[0])
        return !s.empty() && wildcard_matching(s.substr(1), p.substr(1));
        
    return false;
}

void test_case_one(){
    string s = "geeks";
    string p = "g*ks";
    bool result = wildcard_matching(s,p);
    cout << boolalpha << result << endl;
}

void test_case_two(){
    string s = "";
    string p = "*";
    bool result = wildcard_matching(s,p);
    cout << boolalpha << result << endl;
}

void test_case_three(){
    string s = "geeksforgeeks";
    string p = "ge?ks*";
    bool result = wildcard_matching(s,p);
    cout << boolalpha << result << endl;
}

void test_case_four(){
    string s = "gee";
    string p = "g*k";
    bool result = wildcard_matching(s,p);
    cout << boolalpha << result << endl;
}

void test_case_five(){
    string s = "pqrst";
    string p = "*pqrs";
    bool result = wildcard_matching(s,p);
    cout << boolalpha << result << endl;
}

void test_case_six(){
    string s = "abcdhghgbcd";
    string p = "abc*bcd";
    bool result = wildcard_matching(s,p);
    cout << boolalpha << result << endl;
}

void test_case_seven(){
    string s = "abcd";
    string p = "abc*c?d";
    bool result = wildcard_matching(s,p);
    cout << boolalpha << result << endl;
}

void test_case_eight(){
    string s = "abcd";
    string p = "*c*d";
    bool result = wildcard_matching(s,p);
    cout << boolalpha << result << endl;
}

void test_case_nine(){
    string s = "abcd";
    string p = "*?c*d";
    bool result = wildcard_matching(s,p);
    cout << boolalpha << result << endl;
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
    return 0;
}

#include <iostream>
#include <map>
#include <stack>
using namespace std;

bool is_valid_paren(string &str, map<char,char> &mp){
    stack<char> st;
    for(char ch : str){
        if(ch == '(' || 
           ch == '{' || 
           ch == '[' || 
           ch == '<')
            st.push(ch);
        else{
            if(!st.empty() && st.top() == mp[ch])
                st.pop();
            else
                return false; 
        }
    }
    return st.empty();
}


int main(){
    map<char, char> paren_map;
    paren_map[')'] = '(';
    paren_map.insert(make_pair<char,char>('}','{'));
    paren_map.insert(make_pair<char,char>(']','['));
    paren_map.insert(make_pair<char,char>('>','<'));
    
    string str = "(())";
    cout << boolalpha << is_valid_paren(str, paren_map) << endl;

    str = "{()}[]";
    cout << boolalpha << is_valid_paren(str, paren_map) << endl;

    str = "[()]{}{[()()]()}";
    cout << boolalpha << is_valid_paren(str, paren_map) << endl;

    str = "[(])";
    cout << boolalpha << is_valid_paren(str, paren_map) << endl;

    return 0;

}

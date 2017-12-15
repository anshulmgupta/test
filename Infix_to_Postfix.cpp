#include <iostream>
#include <stack>

using namespace std;

int get_operator_priority(char op)
{
    int priority = 0;

    switch (op)
    {
    case '+':
    case '-':
        priority = 0;
        break;
    case '*':
    case '/':
        priority = 1;
        break;
    case '^':
        priority = 2;
        break;
    default:
        priority = -1;
    }

    return priority;
}

string infix_postfix(string infix){

    stack<char> st;
    string postfix;
    for(auto &ch : infix){
        if(isalpha(ch))
            postfix.push_back(ch);
        else if(ch == '(')
            st.push(ch);
        else if(ch == ')'){
            while(!st.empty() && st.top() != '('){
                postfix.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
        else{
            if(st.empty())
                st.push(ch);
            else{
                while(!st.empty() && st.top() != '(' && get_operator_priority(st.top()) >= get_operator_priority(ch)){
                    postfix.push_back(st.top());
                    st.pop();
                }
                st.push(ch);
            }
        }
    }

    while(!st.empty()){
        postfix.push_back(st.top());
        st.pop();
    }

    return postfix;

}

void test_case_one(){
    string infix = "(A+B)*(C+D)";
    auto postfix = infix_postfix(infix);
    cout << "Postfix = " << postfix << " For Infix = " << infix << endl;
    cout << endl;
}

void test_case_two(){
    string infix = "A+B*(C^D-E)^(F+G*H)-I";
    auto postfix = infix_postfix(infix);
    cout << "Postfix = " << postfix << " For Infix = " << infix << endl;
    cout << endl;
}

void test_case_three(){
    string infix = "A*B+C";
    auto postfix = infix_postfix(infix);
    cout << "Postfix = " << postfix << " For Infix = " << infix << endl;
    cout << endl;
}

int main(){
    test_case_one();
    test_case_two();
    test_case_three();
    return 0;
}

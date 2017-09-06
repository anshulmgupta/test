#include <iostream>

using namespace std;

void reverse(string &str, int start, int end){
    while(start <= end){
        swap(str[start], str[end]);
        ++start;
        --end;
    }
}

void reverse_words(string &str){
    reverse(str, 0, str.length()-1);    
    int start = 0;
    int end = 0;
    while(end < str.length()){
        if(isspace(str[end])){
            reverse(str, start, end-1);
            start = end + 1;
        }
        
        end++;
    }
    reverse(str, start, str.length()-1);
}

void reverse_words_trim(string &str){
    int end = str.length();
    int idx = 0;
    int start = 0;
    int len=0;
    bool is_word = false;
    while(idx < end){
        if(isspace(str[idx])){
            idx++;
            continue;
        }
        if(is_word)
            str[len++] = ' ';
        start = len;
        while( idx < end && !isspace(str[idx])){
            str[len++] = str[idx++];
        }
        is_word = true;
        reverse(str, start, len - 1);
    }
    str.resize(len);
    reverse(str, 0, len - 1);

}

int main(){
    cout << "Enter String : ";
    string str;
    getline(cin, str);
    string tmp_string = str;
    //reverse(str, 0, str.length() - 1);
    //reverse_words(str);
    reverse_words_trim(str);
    cout << "Reversal of Words in String " << tmp_string << " is :: " << str << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int find_length(string &str1, string &str2){

    int n = str1.length();
    int m = str2.length();
    int max_len = INT_MIN;
    vector<vector<int>> table(n, vector<int>(m, 0));
    vector<string> result;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(str1[i] == str2[j]){
                if(i==0 || j==0){
                    table[i][j] = 1;
                }
                else{
                    table[i][j] = 1 + table[i-1][j-1];
                }
                if(table[i][j] > max_len){
                    max_len = table[i][j];
                    string str = str2.substr(j-max_len+1, max_len);
                    result.clear();
                    result.push_back(str);
                }
                else if(table[i][j] == max_len){
                    string str = str2.substr(j-max_len+1, max_len);
                    result.push_back(str);
                }
            }
        }
    }
    for(auto str : result)
        cout << str << endl;
    return max_len;
}

void test_case_one(){
    string str1 = "ABAB";
    string str2 = "BABA";
    int len = find_length(str1, str2);
    cout << "Length of longest common substring = " << len << endl;
}

int main(){
    test_case_one();
    return 0;
}

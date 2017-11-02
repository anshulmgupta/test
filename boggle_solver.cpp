/*
 * Complete the function below.
 */
#include<iostream>
#include<cstring>
#include <vector>
using namespace std;
bool is_valid_word(string &str, vector < string > &dictionaryList){
     for (int i=0; i<dictionaryList.size(); i++)
        if (str.compare(dictionaryList[i]) == 0)
          return true;
    return false;
}

void is_word_exists(vector < vector < string > > &board, int i, int j, 
                    string res, vector<string> &result, 
                    vector < string > &dictionaryList, vector<vector<bool>>& visited){
                      
    visited[i][j] = true;
    res = res + board[i][j];
    string ch = board[i][j];
    board[i][j] = "#";
    if(is_valid_word(res, dictionaryList)){
        cout << res << endl;
        result.push_back(res);
    }
    for (int row=i-1; row<=i+1; row++){
        for (int col=j-1; col<=j+1; col++){
            if (row>=0 && col>=0 && row<board.size() && col<board[0].size() && !(board[row][col].compare("#") == 0))
                is_word_exists(board, row, col, res, result, dictionaryList, visited);
        }
    }
    res.pop_back();
    board[i][j] = ch;
}


vector < string > findWords(vector < string > dictionaryList, vector < vector < string > > board) {
    vector<string> result;
    string str = "";
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            is_word_exists(board, i, j, str, result, dictionaryList, visited);
        }
    }
    return result;
}

int main(){
  vector< vector<string> > board = {{"G","I","Z"},
                                    {"U","E","K"},
                                    {"Q","S","E"}};
  vector<string> dictionary = {"GEEKS", "FOR", "QUIZ", "GO"};
  findWords(dictionary, board);
}

/*

1) Every substring is a prefix of some suffix of T

Check whether q is a substring of T:
    Follow the path for q starting from the root.
    If you exhaust the query string, then q is in T.

Check whether q is a suffix of T:
    Follow the path for q starting from the root.
    If you end at a leaf at the end of q, then q is a suffix of T

Count # of occurrences of q in T:
    Follow the path for q starting from the root.
    The number of leaves under the node you end up in is the
        number of occurrences of q.

Find the longest repeat in T:
    Find the deepest node that has at least 2 leaves under it.

Find the lexicographically (alphabetically) first suffix:
    Start at the root, and follow the edge labeled with the
    lexicographically (alphabetically) smallest letter.
*/

#include <iostream>
#include <map>
using namespace std;

struct TrieNode{
    map<char, TrieNode*> childrens;
};

struct Result{
    TrieNode *node;
    int depth;
    int no_leafs;
};

class SuffixTrie{

    TrieNode *root = nullptr;
public:
    SuffixTrie(string str){
        root = new TrieNode();
        _insert(str+"$");
    }

    void _insert(string str){
        for(int i=0;i<str.length();i++){
            TrieNode *curr = root;
            for(int j = i; j < str.length(); j++){
                if(curr->childrens.count(str[j]) == 0)
                    curr->childrens[str[j]] = new TrieNode();
                curr = curr->childrens[str[j]];
            }
        }
    }

    TrieNode* _search(string str){
        TrieNode *curr = root;
        for(int i=0;i<str.length();i++){
            if(curr->childrens.count(str[i]) == 0)
                return nullptr;
            curr = curr->childrens[str[i]];
        }
        return curr;
    }

    bool is_substring(string str){
        TrieNode *curr = _search(str);
        if(curr != nullptr)
            return true;
        return false;
    }

    bool is_suffix(string str){
        TrieNode *curr = _search(str);
        if(curr!=nullptr && curr->childrens.count('$') != 0)
            return true;
        return false;
    }
   
    int no_leafs(TrieNode *curr){
        if(curr->childrens.size() == 0)
            return 1;
        int count = 0;
        for(auto const &d : curr->childrens){
            count += no_leafs(d.second);
        }
        return count;
    }

    int no_occurances(string str){
        TrieNode *curr = _search(str);
        if(curr == nullptr)
            return 0;
        return no_leafs(curr);
    }

    int find_deepest_node(TrieNode *curr, int curr_ht, int &max_depth, TrieNode *&node){
        if(curr->childrens.size() == 0)
            return 1;
        int no_leafs = 0;
        for(auto &d : curr->childrens){
            no_leafs += find_deepest_node(d.second, curr_ht + 1, max_depth, node);
        }
        
        if(no_leafs >= 2 && curr_ht > max_depth){
            node = curr;
            max_depth = curr_ht;
        }
        return no_leafs;
    }

    void find_longest_rep_substring(TrieNode *curr, TrieNode *node, string res, string &result){
        if(curr == nullptr || curr->childrens.size() == 0)
            return;
        if(curr == node){
            result = res;
            return;
        }
        for(auto &d : curr->childrens){
            res.push_back(d.first);
            find_longest_rep_substring(d.second, node, res, result);
            res.pop_back();
        }
    }

    string find_deepest_node(){
        TrieNode *curr = root;
        int max_depth = 0;
        TrieNode *node = nullptr;
        auto result = find_deepest_node(curr, 0, max_depth, node);
        curr = root;
        string res;
        find_longest_rep_substring(curr, node, "", res);
        return res;
    }

};

void test_case_one(){
    string str = "abaaba";
    SuffixTrie s(str);
    bool is_substr = s.is_substring("baa");
    cout << boolalpha << is_substr << endl;
    cout << boolalpha << s.is_substring("baabb") << endl;
    cout << boolalpha << s.is_suffix("baa") << endl;
    cout << boolalpha << s.is_suffix("aba") << endl;

    cout << "No. of occurances of aba in abaaba = " << s.no_occurances("aba") << endl;

    cout << s.find_deepest_node() << endl;

}

void test_case_two(){
    string str = "GEEKSFORGEEKS";
    SuffixTrie s(str);
    cout << s.find_deepest_node() << endl;
}

int main(){
    test_case_one();
    test_case_two();
    return 0;
}

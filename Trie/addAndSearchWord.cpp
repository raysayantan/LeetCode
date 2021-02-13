/*
Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
 

Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
 

Constraints:

1 <= word.length <= 500
word in addWord consists lower-case English letters.
word in search consist of  '.' or lower-case English letters.
At most 50000 calls will be made to addWord and search.
*/
class Trie{
public:
    Trie* next[26];
    bool isWord = false;
    Trie(){
        for(int i = 0; i < 26; i++)
            next[i] = NULL;
    }
};
class WordDictionary {
public:
    Trie *trie;
    /** Initialize your data structure here. */
    WordDictionary() {
        trie = new Trie();
    }
    
    void addWord(string word) {
        Trie *p = trie;
        for(int idx = 0; idx < word.length(); idx++){
            char c = word[idx];
            if(p->next[c - 'a'] == NULL)
                p->next[c - 'a'] = new Trie();
            p = p->next[c - 'a'];
        }
        p->isWord = true;
    }
    
    bool search(string word) {
        return helper(trie, word, 0);
    }
    bool helper(Trie *trie, string word, int idx){
        if(idx == word.length()) {
            if(trie->isWord == true) {
                return true;
            }
            return false;
        }
        char c = word[idx];
        if(c != '.'){
            return (trie->next[c - 'a'] != NULL && helper(trie->next[c - 'a'], word, idx + 1));
        } else {
            bool status = false;
             for(int i = 0; i < 26; i++){
                if(trie->next[i] != NULL){
                    status |= helper(trie->next[i], word, idx + 1);
                    if(status == true) return true;
                }
            }
            return status;
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

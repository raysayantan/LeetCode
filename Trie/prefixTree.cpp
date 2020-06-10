/*
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
*/
class Trie {
    bool isWord;
    vector<Trie*> next;
public:
    /** Initialize your data structure here. */
    Trie() {
        isWord = false;
        vector<Trie*> v(26, NULL);
        next = v;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int l = word.length();
        Trie* p = this;
        for(int idx = 0; idx < l; idx++){
            if(p->next[word[idx] - 'a'] == NULL){
                Trie* temp = new Trie();
                if(idx == l - 1){
                    temp->isWord = true;
                }
                p->next[word[idx]- 'a'] = temp;
            } else {
                if(idx == l - 1)
                    p->next[word[idx]- 'a']->isWord = true; 
            }
            p = p->next[word[idx] - 'a'];
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int l = word.length();
        bool flag = false;
        Trie* p = this;
        for(int idx = 0; idx < l; idx++){
            int index = word[idx] - 'a';
            if((p->next[index]) == NULL ){
                return false;
            } else {
                if(idx == l - 1){
                    if(p->next[index]->isWord != true){
                        return false;
                    } else {
                        flag = true;
                    }
                }
            }
            
            p = p->next[index];
        }
        
        return flag;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int l = prefix.length();
        if(l == 0) 
            return false;
        Trie* p = this;
        for(int idx = 0; idx < l; idx++){
            int index = prefix[idx] - 'a';
            if((p->next[index]) == NULL ){
                return false;
            }
            p = p->next[index];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

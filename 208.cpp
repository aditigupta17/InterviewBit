class TrieNode{
  public:
    TrieNode* next[26];
    bool isEnd;
    TrieNode(bool end = false)
    {
        memset(next, 0, sizeof(next));
        isEnd = end;
    }
};

class Trie {
public:
    TrieNode* root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* temp = root;
        for(int i = 0; i < word.size(); i++)
        {
            if(temp->next[word[i] - 'a'] == NULL)
                temp->next[word[i] - 'a'] = new TrieNode();
            temp = temp->next[word[i] - 'a'];
        }
        temp->isEnd = true;
    }
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* temp = find(word);
        return (temp != NULL) && (temp->isEnd);
    }
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix) != NULL;
    }
    
private:
    TrieNode* find(string key)
    {
        TrieNode* temp = root;
        for(int i = 0; i < key.size() && temp; i++)
            temp = temp->next[key[i] - 'a'];
        return temp;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

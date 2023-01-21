class Trie {
public:

    struct TrieNode {
        bool isEnd;
        TrieNode *nextChar[26];
    };

    TrieNode *getNode() {
        TrieNode *node = new TrieNode();
        node->isEnd = false;
        for(int i = 0; i < 26; i++) node->nextChar[i] = nullptr;
        return node;
    }

    TrieNode *root;

    Trie() {
        root = getNode();
    }
    
    void insert(string word) {
        TrieNode *tp = root;
        for(char ch : word) {
            if(tp->nextChar[ch - 'a'] == nullptr) {
                tp->nextChar[ch - 'a'] = getNode();
            }
            tp = tp->nextChar[ch-'a'];
        }
        tp->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode *tp = root;
        for(char ch : word) {
            if(tp->nextChar[ch - 'a'] == nullptr) return false;
            tp = tp->nextChar[ch - 'a'];
        }
        return tp->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode *tp = root;
        for(char ch : prefix) {
            if(tp->nextChar[ch - 'a'] == nullptr) return false;
            tp = tp->nextChar[ch - 'a'];
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
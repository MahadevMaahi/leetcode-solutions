class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int len = wordList.size(), size, level = 0;
        if(len == 0 || beginWord == endWord) return 0;
        unordered_set<string> uSet;
        for(string str : wordList) uSet.insert(str);
        if(uSet.count(endWord) == 0) return 0;
        queue<string> q;
        q.push(beginWord);
        while(!q.empty()) {
            size = q.size();
            level++;
            while(size--) {
                string str = q.front();
                for(int i = 0; i < str.length(); i++) {
                    char och = str[i];
                    for(char ch = 'a'; ch <= 'z'; ch++) {
                        if(ch != och) {
                            str[i] = ch;
                            if(str == endWord) return level + 1;
                            else if(uSet.count(str)) {
                                q.push(str);
                                uSet.erase(str);
                            }
                        }
                    }
                    str[i] = och;
                }
                q.pop();
            }
        }
        return 0;
    }
};
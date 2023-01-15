class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int len = s.length(), i = 0, size;
        vector<string> ans;
        if(len == 0) return ans;
        unordered_set<string> uSet;
        for(string str : wordDict) uSet.insert(str);
        unordered_map<int, vector<string>> uMap;
        vector<string> temp;
        for(int i = -1; i < len; i++) uMap.insert({i, temp});
        uMap[-1].push_back("");
        vector<int> mIndex; mIndex.push_back(-1);
        for(int i = 0; i < len; i++) {
            size = mIndex.size();
            for(int j = size - 1; j >= 0; j--) {
                if(uSet.count(s.substr(mIndex[j] + 1, i - mIndex[j]))) {
                    for(string str : uMap[mIndex[j]]) {
                        uMap[i].push_back(str + " " + s.substr(mIndex[j] + 1, i - mIndex[j]));
                    }
                    if(mIndex.back() != i) mIndex.push_back(i);
                }
            }
        }
        for(string str : uMap[len - 1]) ans.push_back(str.substr(1));
        return ans;
    }
};
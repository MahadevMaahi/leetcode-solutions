class Solution {
public:

    vector<int> findHash(string str) {
        vector<int> _hash(26, 0);
        for(char ch : str) _hash[ch - 'a']++;
        return _hash;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int len = strs.size(); vector<vector<string>> ans;
        unordered_map<vector<int> vector<string>> mp;
        for(string str : strs) {
            vector<int> _hash = findHash(str);
            if(mp.find(_hash) == mp.end()) {
                vector<string> s; s.push_back(str);
                mp.insert({_hash, s});
            } else mp[_hash].push_back(str);
        }
        for(auto itr = mp.begin(); itr != mp.end(); itr++) {
            ans.push_back(itr->second);
        }
        return ans;
    }
};
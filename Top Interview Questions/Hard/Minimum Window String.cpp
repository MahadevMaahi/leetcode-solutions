class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length() == 0 || t.length() == 0) return "";
        unordered_map<char, int> tMap, sMap;
        for(char ch : t) 
            if(tMap.find(ch) == tMap.end()) tMap[ch] = 1; else tMap[ch]++;
        int curr = 0, req = tMap.size(), i = 0, j = 0, len = s.length(), mLen = INT_MAX, mi = -1;
        while(j < len) {
            char ch = s[j];
            if(tMap.find(ch) != tMap.end()) {
                if(sMap.find(ch) == sMap.end()) sMap[ch] = 1; else sMap[ch]++;
                if(sMap[ch] == tMap[ch]) curr++;
            }
            while(curr == req) {
                while (i < j && sMap.find(s[i]) == sMap.end()) i++;
                if(mLen > (j - i + 1)) {
                    mi = i;
                    mLen =(j - i + 1);
                }
                sMap[s[i]]--;
                if(sMap[s[i]] < tMap[s[i]]) curr--;
                i++;
            }
            j++;
        }
        if(mLen == INT_MAX) return "";
        else return s.substr(mi, mLen);
    }
};
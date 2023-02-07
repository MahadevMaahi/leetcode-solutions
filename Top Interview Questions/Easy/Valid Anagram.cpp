class Solution {
public:
    bool isAnagram(string s, string t) {
        int len1 = s.length(), len2 = t.length();
        if(len1 != len2) return false;
        vector<int> _hash(26, 0);
        for(char ch : s) _hash[ch - 'a']++;
        for(char ch : t) _hash[ch - 'a']--;
        for(int i = 0; i < 26; i++) if(_hash[i] != 0) return false;
        return true;
    }
};
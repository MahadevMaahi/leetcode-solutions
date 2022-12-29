class Solution {
public:
    string countAndSay(int n) {
        string str = "1", nextStr;
        for(int i = 2; i <= n; i++) {
            nextStr = "";
            int len = str.length(), j = 0, cnt;
            while (j < len) {
                cnt = 0;
                while((j + cnt) < len && str[j] == str[j + cnt]) cnt++;
                nextStr = nextStr + to_string(cnt) + str[j];
                j = cnt;
            }
            str = nextStr;
        }
        return str;
    }
};
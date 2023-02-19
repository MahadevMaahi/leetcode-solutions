class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int len = letters.size(), low = 0, high = len - 1, mid, ans = -1;
        while(low <= high) {
            mid = (low + high) / 2;
            if(letters[mid] <= target) low = mid + 1;
            else {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans == -1 ? letters[0] : letters[ans];
    }
};
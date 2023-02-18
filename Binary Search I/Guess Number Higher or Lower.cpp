/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long int low = 1, high = n, mid, gus;
        while(low < high) {
            mid = (low + high) / 2;
            gus = guess(mid);
            if(gus == 0) return mid;
            else if(gus == -1) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};
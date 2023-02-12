class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int len = arr.size(), low = 0, high = len - 1, mid;
        if(len == 0 || len == 1) return 0;
        else if(len == 2) return 1;
        while(low <= high) {
            mid = (low + high) / 2;
            if((mid == 0 || arr[mid] > arr[mid - 1]) && (mid == len - 1 || arr[mid] > arr[mid + 1])) {
                return mid;
            } else if(mid == 0 || arr[mid] > arr[mid - 1]) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};
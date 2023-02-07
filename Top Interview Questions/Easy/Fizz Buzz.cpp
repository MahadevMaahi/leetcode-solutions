class Solution {
public:
    vector<string> fizzBuzz(int n) {
        string f = "Fizz", b = "Buzz", fb = "FizzBuzz";
        vector<string> str;
        for(int i = 0; i < n; i++) {
            if((i+1) % 15 == 0) {
                str.push_back(fb);
            } else if((i+1) % 5 == 0) {
                str.push_back(b);
            } else if((i+1) % 3 == 0) {
                str.push_back(f);
            } else {
                str.push_back(to_string(i+1));
            }
        }
        return str;
    }
};
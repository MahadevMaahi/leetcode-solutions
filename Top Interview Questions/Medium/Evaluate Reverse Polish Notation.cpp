class Solution {
public:

    void evaluateValue(stack<int> &stk, string str) {
        int a = stk.top(); stk.pop();
        int b = stk.top(); stk.pop();
        if(str == "+") stk.push(b + a);
        else if(str == "-") stk.push(b - a);
        else if(str == "*") stk.push(b * a);
        else if(str == "/") stk.push(b / a);
    }

    int evalRPN(vector<string>& tokens) {
        int len = tokens.size(), i;
        if(len == 0) return 0;
        stack<int> stk;
        for(string str : tokens) {
            if(str == "+" || str == "-" || str == "*" || str == "/")
                evaluateValue(stk, str);
            else 
                stk.push(stoi(str));
        }
        return stk.top();
    }
};
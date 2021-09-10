class Solution {
public:
    bool isOperator(string &s)
    {
        return (s == "+" || s == "-" || s == "*" || s == "/");
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        
        for(string s :  tokens)
        {
            if(isOperator(s))
            {
                int val1 = stk.top(); stk.pop();
                int val2 = stk.top(); stk.pop();
                
                if(s == "+")        stk.push(val2 + val1);
                else if(s == "-")   stk.push(val2 - val1);
                else if(s == "*")   stk.push(val2 * val1);
                else                stk.push(val2 / val1);
                
            }else{
                stk.push( stoi(s) );
            }
            
        }
        return stk.top();
    }
};

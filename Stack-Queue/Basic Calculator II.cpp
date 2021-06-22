class Solution {
public:
    int calculate(string s)
    {
        int n = s.size();
        stack<int> st;
        char sign = '+';
        for(int i=0;i<n;i++)
        {
            if(isdigit(s[i]))
            {
                long long num = 0;
                while(i<n && isdigit(s[i]))
                {
                    num = num*10 + s[i]-'0';
                    i++;
                }
                i--;
                
                if(sign=='+')
                    st.push(num);
                else if(sign=='-')
                    st.push(-num);
                else if(sign=='*')
                {
                    long long prev = st.top();
                    st.pop();
                    st.push(prev*num);
                }
                else if(sign=='/')
                {
                    long long prev = st.top();
                    st.pop();
                    st.push(prev/num);
                }
            }
            else if(s[i]!=' ')
                sign = s[i];
        }
        long long ans = 0;
        while(!st.empty())
        {
            long long k =st.top();
            st.pop();
            ans+=k;
        }
        return ans;
    }
};

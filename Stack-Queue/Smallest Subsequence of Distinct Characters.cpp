//https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

// Input: s = "cbacdcbc"
// Output: "acdb"
class Solution {
public:
    string smallestSubsequence(string s) 
    {
        int last_index[26];
        for (int i = 0; i < s.length(); i++)
            last_index[s[i] - 'a'] = i; // track the lastIndex of character presence
        
        bool seen[26] = {0}; // keep track seen
        stack<char> st;
        
        for (int i = 0; i < s.length(); i++) 
        {
            char c = s[i];
            if (seen[c - 'a']) 
                continue; // if seen continue as we need to pick one char only
            
            while (!st.empty() && st.top() > c && i < last_index[st.top()-'a'])
            {
                char x = st.top();
                seen[x -'a'] = false;
                st.pop();// pop out and mark unseen
            }
            st.push(c); // add into stack
            seen[c-'a'] = true; // mark seen
        }

        string res = "";
        while (!st.empty())
        {
            res = st.top() + res;
            st.pop();
        }
        return res;
        
    }
};

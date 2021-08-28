/*Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

Note that the same word in the dictionary may be reused multiple times in the segmentation.
  
Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]
*/
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        unordered_set<string> yes;
        for(auto x : wordDict)
            yes.insert(x);
        string curr = "";
        vector<string> res;
        solve(s,0,yes,curr,res);
        return res;
    }
    void solve(string s,int indx,unordered_set<string> &yes,string curr, vector<string>& res)
    {
        if(indx==s.size())
        {
            curr.pop_back();
            res.push_back(curr);
            return;
        }
        string str = "";
        for(int i=indx;i<s.size();i++)
        {
            str.push_back(s[i]);
            if(yes.count(str))
            {
                solve(s,i+1,yes,curr+str+" ",res);
            }
        }
    }
};

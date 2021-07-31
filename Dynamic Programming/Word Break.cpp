// Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
// Note that the same word in the dictionary may be reused multiple times in the segmentation.
// Input: s = "applepenapple", wordDict = ["apple","pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".

  class Solution {
public:
    bool solve(string s,unordered_set<string> &yes,unordered_map<string,bool> &mp)
    {
        if(yes.find(s)!=yes.end())
            return mp[s] = true;
        
        if(mp.find(s)!=mp.end())
            return mp[s];
        for(int i=0;i<s.size();i++)
        {
            string temp1 = s.substr(0,i);//first task is to find the very first partision and them us point se batwara kr ke uske agge vale pure string pr same operation lgna h
            string temp2 = s.substr(i);
            
            if(yes.find(temp1)!=yes.end())//sbse phle bhai ka mil gya
            {
                if(solve(temp2,yes,mp))// ab agge sare bhai ka mila tb hi return hoga
                    return mp[s] = true;
            }
        }
        return mp[s] = false;
    }
    bool wordBreak(string s, vector<string>& dict) 
    {
        //partision s such that every word occur in dict   
        //if possible return true else return false
        
        int n = s.size();
        unordered_map<string,bool> mp;
        unordered_set<string> yes;
        for(auto x : dict)
            yes.insert(x);
        return solve(s,yes,mp);
    }
};

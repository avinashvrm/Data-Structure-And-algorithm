/*
Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. 
If there are multiple answers, you may return any of them.

Example 1:

Input: nums = ["01","10"]
Output: "11"
Explanation: "11" does not appear in nums. "00" would also be correct.
Example 2:

Input: nums = ["00","01"]
Output: "11"
Explanation: "11" does not appear in nums. "10" would also be correct.
*/
class Solution {
public:
    bool solve(int n, unordered_set<string> &present,string &res,int i)
    {
        if(i==n)
        {
            if(present.count(res))
                return false;
            return true;
        }
        res.push_back('0');
        if(solve(n,present,res,i+1))
            return true;
        res[i] = '1';
        if(solve(n,present,res,i+1))
            return true;
        res.pop_back();
        return false;
    }
    string findDifferentBinaryString(vector<string>& nums) 
    {
        int n=nums[0].size();
        unordered_set<string> present;
        for(auto x : nums)
            present.insert(x);
        string res="";
        solve(n,present,res,0);
        return res;
    }
};

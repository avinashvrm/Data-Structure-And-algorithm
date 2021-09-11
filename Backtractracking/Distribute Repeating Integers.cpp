/*
You are given an array of n integers, nums, where there are at most 50 unique values in the array. You are also given an array of m customer order quantities, quantity, where quantity[i] is the amount of integers the ith customer ordered. Determine if it is possible to distribute nums such that:

The ith customer gets exactly quantity[i] integers,
The integers the ith customer gets are all equal, and
Every customer is satisfied.
Return true if it is possible to distribute nums according to the above conditions.

Example 1:

Input: nums = [1,2,3,4], quantity = [2]
Output: false
Explanation: The 0th customer cannot be given two different integers.
Example 2:

Input: nums = [1,2,3,3], quantity = [2]
Output: true
Explanation: The 0th customer is given [3,3]. The integers [1,2] are not used.
Example 3:

Input: nums = [1,1,2,2], quantity = [2,2]
Output: true
Explanation: The 0th customer is given [1,1], and the 1st customer is given [2,2].
Example 4:

Input: nums = [1,1,2,3], quantity = [2,2]
Output: false
Explanation: Although the 0th customer could be given [1,1], the 1st customer cannot be satisfied.
*/
class Solution {
public:
    bool res = false;
    void solve(vector<int>& quantity,vector<int>& freq,int pos)
    {
        if(pos==quantity.size() || res)
        {
            res = true;
            return;
        }
        for(int i=0;i<freq.size();i++)
        {
            int n = freq[i];
            //cout<<n<<" ";
            if(n>=quantity[pos])
            {
                freq[i]-=quantity[pos];
                solve(quantity,freq,pos+1);
                freq[i]+=quantity[pos];
            }
        }
    }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) 
    {
        unordered_map<int,int> mp;
        for(auto x : nums)
            mp[x]++;
        //priority_queue<int> freq;
        vector<int> freq;
        for(auto x : mp)
            freq.push_back(x.second);
        //sort(freq.rbegin(),freq.rend());
        sort(quantity.rbegin(),quantity.rend());
        solve(quantity,freq,0);
        return res;
    }
};

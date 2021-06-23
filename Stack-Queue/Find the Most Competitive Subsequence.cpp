class Solution {
public
  
  //Input: nums = [3,5,2,6], k = 2
  //Output: [2,6]
  //Explanation: Among the set of every possible subsequence: {[3,5], [3,2], [3,6], [5,2], [5,6], [2,6]}, [2,6] is the most competitive.
  
  //Input: nums = [2,4,3,3,5,4,9,6], k = 4
  //Output: [2,3,3,4]
    vector<int> mostCompetitive(vector<int>& nums, int k) 
    {
        int n = nums.size();
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && st.top()>nums[i] && n-i-1 >= k-st.size())//Agar koi chota element milta h then, stk ke top se compare krnge and array m remaining eles must be >= req elemenst tb hi pop kr paenge
                st.pop();
               
            if(st.size() < k)
                st.push(nums[i]);
        }
        vector<int> res;
        while(!st.empty())
        {
            int t = st.top();st.pop();
            res.push_back(t);
        }
        reverse(res.begin(),res.end());
        return res;
            
    }
};

class Solution {
public:
    vector<vector<int>> result;
    void solve(vector<int>& nums , int start , vector<int>& subset)
    {
        result.push_back(subset);
        
        for(int i=start ;i<nums.size();i++)
        {
            if(i>start and nums[i-1] == nums[i])
                continue;
            
            subset.push_back(nums[i]);
            solve(nums , i+1 , subset);
            subset.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin() , nums.end());
        vector<int> subset;
        solve(nums, 0 , subset);
        return result;
    }
};
/*
  The subset and permutation problems all have similar code. However, I did not find one that explains the difference between them. 
  And despite the fact that they have similar code, actually they are very different.

subset I, II
My codes are similar to many others: push one element into the vector and then recursively call the function. After that pop that element out.

Explanation: The subset problem is all about choice, whether you want certain element inside the vector or not.
For example, [1, 2, 3], starting with pos = 0. At pos = 0, you push 1 into temp, then recursively call the function.
Then this reclusive call is a "crossroad". Inside the call (with all other calls inside), you have the "1" chosen and every vector you produce will begin with 1. When the call returns (ie. you pop 1 out), you are on the other road of the crossroad, which does not contain 1.
These are just the first "choice" you are faced. And after that you face with other similar choices.

subset II : 
Eliminate the dup with sort and then the condition: 
do not put this element inside, if it has same element before && the former dup has not been put into it. Because otherwise, you better off put the former dup into the vector instead of this (latter dup) one.

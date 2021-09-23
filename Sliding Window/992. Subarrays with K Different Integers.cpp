// Input: nums = [1,2,1,2,3], k = 2
// Output: 7
// Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
// Example 2:

// Input: nums = [1,2,1,3,4], k = 3
// Output: 3
// Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].

class Solution 
{
public:
    int solve(vector<int>&nums,int k)
    {
        unordered_map<int,int>m;
        int j=0,ans=0;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
            while(m.size()>k)
            {
                if(m[nums[j]]>1)
                {
                    m[nums[j]]--;
                }
                else
                {
                    m.erase(nums[j]);
                }
                j++;
            }
            ans+=(i-j+1);
        }
        //cout<<ans<<" ";
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
        return solve(nums,k)-solve(nums,k-1);
    }
};

/*
Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

 

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There is no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
class Solution {
public:
    //just like sum ==k in  0,1 array 
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        int i=0,j=0,n=nums.size();
        int ans=0,odd=0,pre=0;
        while(i<n)
        {
            cout<<i<<" ";
            if(nums[i]&1)
                odd++;
            while(j<n && odd>k)
            {
                odd-=(nums[j]&1?1:0);
                j++;
                pre=0;
            }
            while(j<i && ((nums[j]&1)==0))
            {
                pre+=1;
                j++;
            }
            if(j<=i && odd==k)
                ans+=pre+1;
            i++;
        }
        return ans;
        
    }
};
*/
class Solution 
{
public:
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]&1)
                nums[i]=1;
            else
                nums[i] = 0;
        }
        int count=0,sum=0;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum==k)
            {
                count++;
            }
            if(m.find(sum-k)!=m.end())
                count+=m[sum-k];
            m[sum]++;
        }
    
        return count;
    }
};

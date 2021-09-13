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
    int numberOfSubarrays(vector<int>& nums, int k)
    {
        int j = 0, odd = 0, count = 0, total = 0;
        for (int i = 0; i < nums.size(); i++) 
        {
            if (nums[i] & 1) 
            {
                odd++;
                if (odd >= k) 
                {
                    count = 1;
                    while (!(nums[j++] & 1)) 
                        count++;
                    total += count;
                }
            } 
            else if (odd >= k) 
                total += count;
        }
        return total;
    }
};
*/


// same as https://leetcode.com/problems/binary-subarrays-with-sum/description/
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

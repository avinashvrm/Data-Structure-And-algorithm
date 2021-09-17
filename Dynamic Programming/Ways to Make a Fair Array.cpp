/*
You are given an integer array nums. You can choose exactly one index (0-indexed) and remove the element. Notice that the index of the elements may change after the removal.

For example, if nums = [6,1,7,4,1]:

Choosing to remove index 1 results in nums = [6,7,4,1].
Choosing to remove index 2 results in nums = [6,1,4,1].
Choosing to remove index 4 results in nums = [6,1,7,4].
An array is fair if the sum of the odd-indexed values equals the sum of the even-indexed values.

Return the number of indices that you could choose such that after the removal, nums is fair.

 

Example 1:

Input: nums = [2,1,6,4]
Output: 1
Explanation:
Remove index 0: [1,6,4] -> Even sum: 1 + 4 = 5. Odd sum: 6. Not fair.
Remove index 1: [2,6,4] -> Even sum: 2 + 4 = 6. Odd sum: 6. Fair.
Remove index 2: [2,1,4] -> Even sum: 2 + 4 = 6. Odd sum: 1. Not fair.
Remove index 3: [2,1,6] -> Even sum: 2 + 6 = 8. Odd sum: 1. Not fair.
There is 1 index that you can remove to make nums fair.
Example 2:

Input: nums = [1,1,1]
Output: 3
Explanation: You can remove any index and the remaining array is fair.
*/

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) 
    {
        int ans=0;
        int totalEve=0,totalOdd=0,currOdd=0,currEve=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i%2==0)
                totalEve+=nums[i];
            else 
                totalOdd+=nums[i];
        }
        for(int i=0;i<nums.size();i++)
        {
            if(i%2==0)
                totalEve-=nums[i];  //if we remove the no. then we have to subtract it from total
            else 
                totalOdd-=nums[i];  //if we remove the no. then we have to subtract it from total
            
            if((totalEve-currEve+currOdd)==(totalOdd-currOdd+currEve))  
                //after removing nums[i] all the evens after i will become odd and all the odds will become even
                ans++;
            
            if(i%2==0)
            {
                totalEve+=nums[i];  //restoring the total of evens for next iterartion
                currEve+=nums[i];  //sum of odds before i
            }
            else
            {
                totalOdd+=nums[i];  ////restoring the total of evens for next iterartion
                currOdd+=nums[i]; //sum of odds before i
            }
        }
        return ans;
    }
};

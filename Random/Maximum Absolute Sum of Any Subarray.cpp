class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) 
    {
       int maxSum = nums[0];
        int minSum = nums[0];
        int currMax=0;
        int currMin=0;
        
        for(int i=0;i<nums.size();i++)
        {
            currMax+=nums[i];
            currMin+=nums[i];
           
            currMax = max(currMax,nums[i]);
            maxSum=max(maxSum,currMax);
            
            currMin = min(currMin,nums[i]);
            minSum=min(minSum,currMin);
        }
        
        return max(maxSum,abs(minSum));
    }
};

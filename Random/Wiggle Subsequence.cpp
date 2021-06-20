class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) 
    {
        // get valley and peak
        int n = nums.size();
        
        if(n == 1){
            return 1;
        }
        
        int index = 0;
        int result = 1;
        bool movedown = false;
        bool moveup = false;
        
        while(index < n-1)
        {
            movedown = false;
            moveup = false;
            
            while(index < n-1 && nums[index] == nums[index+1])
                index++;
            
            while(index < n-1 && nums[index] >= nums[index+1])
            {
                movedown = true;
                index++;
            }
            if(movedown == true){
                result++;
            }

            while(index < n -1 && nums[index] <= nums[index+1])
            {
                moveup = true;
                index++;
            }
            if(moveup == true){
                result++;
            }
            
        }
        
        return result;
    }
};

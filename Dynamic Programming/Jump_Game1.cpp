class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int jump = 0;
        int curr_max = 0;
     
        for(int i = 0;i<nums.size()-1;i++)
        {
            curr_max = max(curr_max,i+nums[i]);
            
            if(i==curr_max)
                break;
            
        }
        return curr_max>=nums.size()-1;
    }
};

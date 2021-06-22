class Solution {
public:
    bool find132pattern(vector<int>& nums) 
    {
        int n = nums.size();
        //132
        stack<int> s;
        int leftmin[n];
        leftmin[0] = nums[0];     
        for(int j=1;j<n;j++)
            leftmin[j] = min(leftmin[j-1],nums[j]);
        
        for(int i = n-1;i>=0;i--)
        {
            if(nums[i] > leftmin[i])
            {
                while(!s.empty() && s.top() <= leftmin[i])
                    s.pop();
                
                if(!s.empty() && s.top() < nums[i])
                {
                    cout<<leftmin[i]<<" "<<s.top()<<" "<<nums[i];
                    return true;
                }
                s.push(nums[i]);
                
            }
        }
        return false;
    }
};

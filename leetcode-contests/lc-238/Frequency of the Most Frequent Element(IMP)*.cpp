class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) //Input: nums = [1,2,4], k = 5
                                               //Output: 3
                                               //Explanation: Increment the first element three times and the second element two times to make nums = [4,4,4].  4 has a frequency of 3.
    {
        sort(nums.begin(),nums.end());
        int ans = 1;
        int n = nums.size();
        long long sum = 0;
        int i=0,j=0;
        while(j<n)
        {
            sum+=nums[j];
            while(sum + k < (long)nums[j]*(j-i+1))
            {
                sum -= nums[i];
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        cout<<j<<" "<<i;
        return ans;
    }
};

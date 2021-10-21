class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) 
    {
        //one move---any integers vale from any array to any value btw [1,6]
        
        int n = nums1.size();
        int m = nums2.size();
        if(6*n < m || 6*m < n)
            return -1;
        int s1 = 0,s2 = 0;
        for(auto x : nums1)
            s1+=x;
        for(auto x : nums2)
            s2+=x;
        if(s1 > s2)
            return minOperations(nums2,nums1);
        int diff = s2 - s1;
        if(diff==0)
            return 0;
        int i = 0,j=0,res=0;
        sort(nums2.rbegin(),nums2.rend());
        sort(nums1.begin(),nums1.end());
    
        while(diff > 0)
        {
            if(j==m || i < n && (6-nums1[i] >= nums2[j]-1))
            {
                diff-=6-nums1[i];
                res++;
                i++;
            }
            else
            {
                diff-=nums2[j]-1;
                res++;
                j++;
            }
        }
        return res;
    }
};

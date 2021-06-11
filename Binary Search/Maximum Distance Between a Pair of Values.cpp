class Solution {
public:
   int maxDistance(vector<int>& nums1, vector<int>& nums2) 
   {
        
        int i = 0, j = 0;
        int n = nums1.size(), m = nums2.size(), maxlen = 0;
                
        while(i < n && j < m)
        {
                 
            while(j < m && nums1[i] <= nums2[j])
                j++;

            maxlen = max(maxlen, j-i-1); 
            
            while(i < n && j < m && nums1[i] > nums2[j])
                i++;            
        }
        
        return maxlen;
    }
};

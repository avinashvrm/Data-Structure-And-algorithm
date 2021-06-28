// https://leetcode.com/problems/create-maximum-number/

// Input: nums1 = [3,4,6,5], nums2 = [9,1,2,5,8,3], k = 5
// Output: [9,8,6,5,3]
//Basic idea is to find best answer from nums1 with size i and from nums2 with size k-i.
//Then we merge the two arrays, the merge function has been optimized to be O(N) . Overall Complexity is O(N^2)
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> res(k);
        for(int i=0;i<=k;i++)
        {
            int j = k-i;//nums1 se i bada element lekr nums2 se k-i bada ele lekr merge
            if(i<=n && j<=m)
            {
                vector<int> ans1 = get_max(nums1,i);
                vector<int> ans2 = get_max(nums2,j);
                vector<int> ans  = merge(ans1,ans2);
                
                res = max(res,ans);
            }
        }
        return res;
    }
    vector<int> merge(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> ans; 
        int i = 0;
        int j = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        while(i<n1 && j<n2) 
        {
            if (nums1[i] > nums2[j])
                ans.push_back(nums1[i++]);
            else if (nums1[i] < nums2[j])
                ans.push_back(nums2[j++]);
            else 
            { // Both are equal, we need to pick the one that is better in the future
                int i1 = i + 1;
                int j1 = j + 1;
                int larger = 0; 
                
                while(i1<n1 && j1 < n2 && !larger) 
                {
                    if(nums1[i1] == nums2[j1]) 
                    {
                        i1++;
                        j1++;
                    }
                    else if (nums1[i1] > nums2[j1]) // nums1 is better to pick 
                        larger = -1;
                    else
                        larger = 1;  // nums2 is better to pick 
                }
                
                if (i1 == n1)
                    larger = 1;
                if (j1 == n2)
                    larger = -1;
                
                if (larger == -1)
                    ans.push_back(nums1[i++]);
                else 
                    ans.push_back(nums2[j++]);
            }
        }
        while(i<n1)
            ans.push_back(nums1[i++]);
        
        while(j<n2)
            ans.push_back(nums2[j++]);
        
        return ans;    
    }
    vector<int> get_max(vector<int>& nums, int k)
    {
        vector<int> st;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && st.back() < nums[i]&& n-i-1>=k-st.size())
                st.pop_back();
            if(st.size()<k)
                st.push_back(nums[i]);
        }
        return st;
    }
};

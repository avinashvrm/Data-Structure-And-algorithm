class Solution {
public:
    int subarraySum(vector<int>& a, int k) 
    {
        int n = a.size();
        if (n == 0) 
            return 0;
        
        unordered_map<int, int>m;
        int cnt = 0;
        int sum = 0;
        for (int i = 0; i<n; i++)
        {
            sum += a[i];
            
            if (sum == k) 
            {
                cnt++;
            }
            
            if (m.find(sum-k) != m.end()) 
            {
                cnt += m[sum-k];
            }
            m[sum]++;
        }
        return cnt;
    }
};

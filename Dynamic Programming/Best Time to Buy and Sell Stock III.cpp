//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/discuss/900051/fully-explained-all-buy-and-sell-problems-c-recursive-memoization-minor-difference
//Problem solutions
class Solution {
public:
    int maxProfit(vector<int>& price) 
    {
        int n = price.size();
        
        int minst = price[0];
        int minst2 = price[n-1];
        int ans = 0;
        
        vector<int> v1(n,0);
        vector<int> v2(n,0);
        for(int i = 1; i<n; i++)
        {
            v1[i] = max(v1[i-1],price[i]-minst);
            minst = min(minst,price[i]);
            //v1.push_back(maxProfit1);
           
            v2[n-1-i] = max(v2[n-i],minst2 - price[n-i-1]);
            minst2 = max(minst2,price[n-i-1]);
            
            //v2.push_back(maxProfit2);
            
        }
        for(int i = 0; i<n; i++)
            ans = max(ans,v1[i] + v2[i]);
        return ans;
        
    }
};

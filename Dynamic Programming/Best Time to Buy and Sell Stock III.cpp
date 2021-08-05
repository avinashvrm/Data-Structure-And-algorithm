//iss post m sara diya h, apne code se acha usse smjh aega!!!
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
// O(N*K)
class Solution {
public:
    int find(vector<int> &prices,int ind,bool buy,int c,vector<vector<vector<int>>> &memo)
    {   
        //if buy =1 means we have to buy now
        //else we have to sell now
        if(ind>=prices.size()||c>=2) return 0; //counter
        if(memo[ind][buy][c]!=-1) return memo[ind][buy][c];
        if(buy) //now we can either buy prices[i] or we can skip it and try next to buy
        {
            return memo[ind][buy][c]=max(-prices[ind]+find(prices,ind+1,!buy,c,memo),find(prices,ind+1,buy,c,memo));
        }
        else  //now we can either sell prices[i] or we can skip it and try next to sell
        {
            return memo[ind][buy][c]=max(prices[ind]+find(prices,ind+1,!buy,c+1,memo),find(prices,ind+1,buy,c,memo));
        }
        
    }
    int maxProfit(vector<int>& prices) {
        //here we can do maximum two transaction
        //Use 3-D vector because here three states i,k,buy/sell
        vector<vector<vector<int>>> memo(prices.size(),vector<vector<int>>(2,vector<int>(2,-1)));
          
       return find(prices,0,1,0,memo); 
    }
};

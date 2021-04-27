class Solution {
public:
    vector<int> dp;
    int sub(vector<int> &day, vector<int> &cost, int si)		// si denotes starting index
    {
        //cout<<"| ";
        int n = day.size();
        if(si>=n)   
            return 0;
        if(dp[si])  
            return dp[si];
        
        int cost_day = cost[0] + sub(day , cost , si+1);
        
        int i;
        for(i = si ; i<n; i++)
            if(day[i] >=day[si] + 7)
                break;
        int cost_week = cost[1] + sub(day, cost, i);
        
        for(i = si ; i<n; i++)
            if(day[i] >=day[si] + 30)
                break;
        int cost_month = cost[2] + sub(day, cost, i);     
        
        return dp[si] = min({cost_day, cost_week , cost_month  });
    }
    
    
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {      
         dp.resize(367);
        return sub(days,costs,0);
    }
};

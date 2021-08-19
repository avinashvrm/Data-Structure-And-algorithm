class Solution {
public:
    int minCost(string s, vector<int>& cost) 
    {
        int costs = 0;
        for(int i = 0;i<s.size()-1;i++)
        {
            
            int k = 1;
            int j=i;
            while(s[i]==s[i+1])
            {
                i++;
                k++;
            }
            
            if(k>1)
            {
                int max_cost = 0;
                int sum = 0;
                for(int x =j;x<k+j;x++)
                {
                    sum+=cost[x];
                    max_cost = max(max_cost,cost[x]);
                }
                costs += sum - max_cost;
            }
        }
        return costs;
    }
};

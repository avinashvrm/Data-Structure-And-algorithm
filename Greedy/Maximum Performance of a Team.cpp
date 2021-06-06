class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) 
    {
        vector<pair<int,int>> perfVec;                                           //speed      = [2,10,3,1,5,8], 
                                                                                 //efficiency = [5,4,3,9,7,2]  O/P : 68    --Expl--(10+5+2)*(min(4,5,7)
        for(int i = 0 ; i < n ; i++)
            perfVec.push_back({efficiency[i],speed[i]});
        
        
        sort(perfVec.begin(),perfVec.end(),[&](pair<int,int> p1,pair<int,int> p2)
             {
            return p1.first > p2.first;
        });
        
        priority_queue<int,vector<int>,greater<int>> pq;
        
        long speedSum = 0, perf = 0;
        for (auto p : perfVec) 
        {
            int currEfficiency = p.first;
            int currSpeed = p.second;
            if (pq.size() >= k ) 
            {
                speedSum -= pq.top();
                pq.pop();
            }
            pq.push(currSpeed); 
            
            speedSum += currSpeed;
            perf = max(perf, speedSum * currEfficiency);
        }
        return (int) (perf % 1000000007);
            
    }
};

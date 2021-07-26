// https://leetcode.com/problems/process-tasks-using-servers/
// Input: servers = [3,3,2], tasks = [1,2,3,2,1,2]
// Output: [2,2,0,2,1,2]

// Explanation: Events in chronological order go as follows:
// - At second 0, task 0 is added and processed using server 2 until second 1.
// - At second 1, server 2 becomes free. Task 1 is added and processed using server 2 until second 3.
// - At second 2, task 2 is added and processed using server 0 until second 5.
// - At second 3, server 2 becomes free. Task 3 is added and processed using server 2 until second 5.
// - At second 4, task 4 is added and processed using server 1 until second 5.
// - At second 5, all servers become free. Task 5 is added and processed using server 2 until second 7.
class Solution {
public:
    typedef pair<int,int> pi;
    typedef pair<int,pi> ppi;
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) 
    {
        priority_queue<pi,vector<pi>,greater<pi>> a_pq;//availble
        priority_queue<ppi,vector<ppi>,greater<ppi>> u_pq;// unavaliable
        
        int n = tasks.size();
        for(int i = 0;i<servers.size();i++)
        {
            a_pq.push({servers[i],i});
        }
        int time = 0;
        vector<int> res;
        
        for(int i = 0;i<n;)
        {
            while(!u_pq.empty() && time>=u_pq.top().first)
            {
                a_pq.push({u_pq.top().second.first, u_pq.top().second.second});
                u_pq.pop();
            }
            
            if(!a_pq.empty())
            {
                while(!a_pq.empty() && i<=time && i<n)
                {
                    auto serv = a_pq.top();
                    a_pq.pop();
                    res.push_back(serv.second);
                    
                    u_pq.push({time+tasks[i],{serv.first,serv.second}});
                    i++;
                }
                time++;
            }
            else
                time = u_pq.top().first;
        }
        
        return res;
    }
};

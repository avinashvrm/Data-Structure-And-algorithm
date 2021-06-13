class Solution {
public:
    int maxResult(vector<int>& nums, int k) 
    {
        int n = nums.size();
        if(n==0)
            return 0;
        priority_queue<pair<int,int>> pq;
        pq.push({nums[0],0});
        int score = nums[0];
        for(int i=1;i<n;i++)
        {
            while(i - pq.top().second > k)
                pq.pop();
            auto s = pq.top();
            score = nums[i] + s.first;
            pq.push({score,i});
        }
        return score;
    }
};

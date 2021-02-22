class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>> v;
        int n = intervals.size();
        if(n==0)
            return v;
        sort(intervals.begin(),intervals.end());
        
        int chalu = intervals[0][0];
        int bound = intervals[0][1];
        for(int i = 1;i<n;i++)
        {
            if(bound >= intervals[i][0])
            {
                bound = max(bound,intervals[i][1]);
            }
            else if(bound < intervals[i][0])
            {
                v.push_back({chalu,bound});
                chalu =  intervals[i][0];
                bound =  intervals[i][1];
            }
        }
        v.push_back({chalu,bound});
        return v;
    }
};

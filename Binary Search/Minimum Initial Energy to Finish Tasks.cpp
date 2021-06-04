//https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/
//After 15 TLE finallyyyy!!! (wherever possible pass vector by refernce)
class Solution {
public:
    bool solve(vector<vector<int>>& tasks,int mid)
    {
        for(auto &x : tasks)// & this one!!
        {
            if(mid < x[1])
                return false;
            
            mid = mid - x[0];
        }
        return mid>=0;
    }
    int minimumEffort(vector<vector<int>>& tasks) 
    {
        sort(tasks.begin(),tasks.end(),[](vector<int>& a, vector<int>& b) {
			int diff1 = a[1] - a[0];
			int diff2 = b[1] - b[0];
			return diff1 > diff2;
		});
        int l = 1;
		int h = INT_MAX;
        while(l<h)
        {
            int mid = l + (h - l) / 2;
            
            if(solve(tasks,mid))
                h = mid;
            else
                l = mid+1;
            
        }
        return h;
    }
};

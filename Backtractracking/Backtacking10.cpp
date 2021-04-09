class Solution {
public:
    void solve(vector<int> &vec,set<vector<int>> &s,vector<int> &temp,int sum, int x)
    {
        if(sum==0)
        {
            s.insert(temp);
            return;
        }
        
        for(int i = x;i<vec.size();i++)
        {
            if(sum-vec[i]>=0)
            {
                temp.push_back(vec[i]);
                sum = sum - vec[i];
                
                solve(vec,s,temp,sum,i+1);
                
                sum = sum + vec[i];
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& vec, int target) 
    {
        sort(vec.begin(), vec.end());
        //vec.erase( unique( vec.begin(), vec.end() ), vec.end() );
        set<vector<int>> s; 
        vector<vector<int>>v;
        vector<int> temp;
        solve(vec,s,temp,target,0);
        for(auto x : s)
            v.push_back(x);
        return v;    
    }
};

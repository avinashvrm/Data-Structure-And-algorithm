Input:
N = 4
arr[] = {7,2,6,5}
B = 16
Output:
(2 2 2 2 2 2 2 2)
(2 2 2 2 2 6)
(2 2 2 5 5)
(2 2 5 7)
(2 2 6 6)
(2 7 7)
(5 5 6)

class Solution {
  public:
    void solve(vector<int> &vec,vector<vector<int>> &v,vector<int> &temp,int sum, int x)
    {
        if(sum==0)
        {
            v.push_back(temp);
            return;
        }
        
        for(int i = x;i<vec.size();i++)
        {
            if(sum-vec[i]>=0)
            {
                temp.push_back(vec[i]);
                sum = sum - vec[i];
                
                solve(vec,v,temp,sum,i);
                
                sum = sum + vec[i];
                temp.pop_back();
            }
        }
    }
    vector<vector<int> > combinationSum(vector<int> &vec, int B) 
    {
        sort(vec.begin(), vec.end());
        vec.erase( unique( vec.begin(), vec.end() ), vec.end() );
        
        vector<vector<int>>v;
        vector<int> temp;
        solve(vec,v,temp,B,0);
        return v;
    }    
};

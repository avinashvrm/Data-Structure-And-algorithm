class Solution {
public:
    void solve(vector<int> &S,int i,vector<int> &temp,vector<vector<int>> &ans)
    {
        if(i==S.size())
        {
            ans.push_back(temp);//base conditiom
            return;
        }
        
        //take ith ele in account
        temp.push_back(S[i]);
        solve(S,i+1,temp,ans);//call of every other ele
        
        temp.pop_back();//not including the ith ele that was include above
        
        solve(S,i+1,temp,ans);//for storing ele without inl ith ele
    }
    vector<vector<int> > subsets(vector<int> &S) 
    {
        int n = S.size();
        vector<vector<int>> ans;
        vector<int> temp;
        solve(S,0,temp,ans);
        return ans;
    }
};

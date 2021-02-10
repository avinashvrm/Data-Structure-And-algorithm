

class Solution{
public:
    int issafe(char cc[][10],int r,int c,int N)
    {
            // return 0 if two queens share the same column
        for (int i = 0; i < r; i++) {
            if (cc[i][c] == 'Q') {
                return 0;
            }
        }
     
        // return 0 if two queens share the same `` diagonal
        for (int i = r, j = c; i >= 0 && j >= 0; i--, j--) 
        {
            if (cc[i][j] == 'Q') 
                return 0;
        }
     
        // return 0 if two queens share the same `/` diagonal
        for (int i = r, j = c; i >= 0 && j < N; i--, j++) 
        {
            if (cc[i][j] == 'Q')
                return 0;
        }
        return 1;
    }
    void solve(char cc[][10],int n,int r,vector<vector<string>> &v)
    {
        if(r==n)
        {
            if(n==1)
                return;
            vector<string> res;
            for(int i =0;i<n;i++)
            {
                string s = "";
                for(int j=0;j<n;j++)
                {
                    s = s + cc[i][j];
                }
                res.push_back(s);
            }
            v.push_back(res);                
            return;
        }
        for(int i = 0; i<n; i++)
        {
            if(issafe(cc,r,i,n))
            {
                cc[r][i] = 'Q';
                solve(cc,n,r+1,v);
                cc[r][i] = '.';
            }
        }
    }
   vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> v;
        if(n==1)
        {
            vector<string> temp;
            string q = "Q";
            temp.push_back(q);
            v.push_back(temp);
        }
        else if(n>1)
        {   
            char cc[10][10];
            memset(cc,'.',sizeof cc);
            solve(cc,n,0,v);
        }
        return v;
    }
};

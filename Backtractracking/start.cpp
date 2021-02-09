//int sol[MAX][MAX] = {0};
void solve(int m[][MAX],int n,int i,int j,vector<string> &v,string s)
{
    if(i>=n || j>=n || i<0 || j<0 || m[i][j]==0)
        return;
    if(i==n-1 && j==n-1)
    {   
        //sol[i][j] = 1;
        v.push_back(s);
        return;
    }
    m[i][j] = 0;
    solve(m,n,i+1,j,v,s+'D');
    solve(m,n,i,j-1,v,s+'L');
    solve(m,n,i,j+1,v,s+'R');
    solve(m,n,i-1,j,v,s+'U');
    
    m[i][j] = 1;
}


vector<string> findPath(int m[MAX][MAX], int n) 
{
    vector<string> v;
    string s = "";
    solve(m,n,0,0,v,s);
    return v;
}
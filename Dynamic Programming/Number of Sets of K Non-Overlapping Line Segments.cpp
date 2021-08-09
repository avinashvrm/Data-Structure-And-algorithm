class Solution {
public:
    int dp1[1002][1002];
    int dp2[1002][1002];
    const int M=1e9+7;
    int mod(int a){
        return (a%M + M)%M;
    }
    int add(int a, int b){
        return mod(mod(a)+mod(b));
    }
    int mul(int a, int b){
        return mod(mod(a)*mod(b));
    }
    int pre(int n, int k)
    {
        if(n<2)
            return 0;
        
        if(dp2[n][k]!=-1)
            return dp2[n][k];
        
        return dp2[n][k] = add(pre(n-1,k) , solve(n,k));
    }
    int solve(int n,int k)
    {
        if(k==1){ // only one seg to make
            return (n*(n-1))/2;
        }
        if(n==1) // only one point
            return 0;
        if(n-1==k) // all segments of lenght 1
            return 1;
        if(n-1<k)
            return 0;
        if(dp1[n][k]!=-1)
            return dp1[n][k];
        int res = 0;
        res = add(res,solve(n-1,k));
        
        // for(int i = 1;i<n;i++)
        // {
        //     res= add(res,solve(n-i,k-1));
        // }
        res = add(res,pre(n-1,k-1));
        
        return dp1[n][k] = res;
        
    }
    int numberOfSets(int n, int k) 
    {
        // 0 1 2 3 4 . . . n
        memset(dp1,-1,sizeof(dp1));
        memset(dp2,-1,sizeof(dp2));
        return solve(n,k);
    }
};

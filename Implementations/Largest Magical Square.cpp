class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid)//avdhu ka code
    {
        int n=grid.size(),m=grid[0].size();
        
        vector<vector<int>> hori=grid;
        vector<vector<int>> ver =grid;
        vector<vector<int>> dig1=grid;
        vector<vector<int>> dig2=grid;
        
        //hori sum
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                hori[i][j]+=hori[i][j-1];
            }
        }
        
        //ver sum
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                ver[i][j]+=ver[i-1][j];
            }
        }
        
        //dig1 sum
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dig1[i][j]+=dig1[i-1][j-1];
            }
        }
        
        //dig2 sum
        for(int i=1;i<n;i++){
            for(int j=m-2;j>=0;j--){
                dig2[i][j]+=dig2[i-1][j+1];
            }
        }
        
        int ans=0;
        for(int cl=0;cl<m;cl++)
        {
            for(int cr=cl;cr<m;cr++)
            {
                for(int rl=0;rl<n;rl++)
                {
                    for(int rr=rl;rr<n;rr++)
                    {
                        cout<<cl<<" "<<cr<<" "<<rl<<" "<<rr<<endl;
                        if((cr - cl)==(rr - rl))//to check if its a square or not
                        {
                            set<int> s;//to check if it is magical or not!!
                            int len = cr - cl + 1;
                            
                            if(rl==0||cl==0)
                            {
                                s.insert(dig1[rr][cr]);
                            }
                            else
                            {
                                s.insert(dig1[rr][cr]-dig1[rl-1][cl-1]);
                            }
                            
                            if(rl==0||cr==m-1)
                            {
                                s.insert(dig2[rr][cl]);
                            }
                            else
                            {
                                s.insert(dig2[rr][cl]-dig2[rl-1][cr+1]);
                            }
                            
                            for(int k=0;k<len;k++)
                            {
                                if(cl==0)
                                {
                                    s.insert(hori[rl+k][cr]);    
                                }
                                else
                                {
                                    s.insert(hori[rl+k][cr]-hori[rl+k][cl-1]);
                                }
                            }
                            
                            for(int k=0;k<len;k++)
                            {
                                if(rl==0)
                                {
                                    s.insert(ver[rr][cl+k]);    
                                }
                                else
                                {
                                    s.insert(ver[rr][cl+k]-ver[rl-1][cl+k]);
                                }
                            }
                            if(s.size()==1)
                            {
                                ans=max(ans,len);
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};

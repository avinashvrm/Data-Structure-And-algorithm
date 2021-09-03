class Solution {
public:
    bool possible(vector<int>& bloomday, int m, int k,int mid)
    {
        int flower = 0;
        int bq = 0;
        for(int i=0;i<bloomday.size();i++)
        {
            if(bloomday[i]<=mid)
            {
                flower++;
                if(flower==k)
                {
                    flower=0;
                    bq++;
                }
            }
            else
                flower = 0;
        }
        return bq>=m;
    }
    int minDays(vector<int>& bloomday, int m, int k) 
    {
        int n = bloomday.size();
        if(m*k > n)
            return -1;
        
        int i = 0;
        int j = 1e9;
        while(i<j)
        {
            int mid = i + (j-i)/2;
            //cout<<mid<<" ";
            if(possible(bloomday,m,k,mid))
                j = mid;
            else
                i = mid+1;
        }
        return i;
    }
};

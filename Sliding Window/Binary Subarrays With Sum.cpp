class Solution 
{
public:
    int numSubarraysWithSum(vector<int>& A, int S) 
    {
        int count=0,sum=0;
        unordered_map<int,int>m;
        for(int i=0;i<A.size();i++)
        {
            sum+=A[i];
            if(sum==S)
            {
                count++;
            }
            if(m.find(sum-S)!=m.end())
            {
                count+=m[sum-S];
            }
            m[sum]++;
        }
        return count;
    }
};

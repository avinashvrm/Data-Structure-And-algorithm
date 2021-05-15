class Solution {
public:
    int count(vector<vector<int>>& matrix, int mid)
    {
        int x = 0;
        int n = matrix.size()-1;
        int j = n;
        for(int i = 0;i<=n;i++)
        {
            for(;j>=0;j--)
            {
                if(matrix[i][j] <= mid)
                {
                    x+=j+1;
                    break;
                }
            }
        }
        return x;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        int n = matrix.size();
        
        int l = matrix[0][0];
        int h = matrix[n-1][n-1];
        
        while(l<h)
        {
            int mid = (l+h)/2;
            int cnt = count(matrix,  mid);
            cout<<mid<<" ";
            if(cnt<k)
                l = mid+1;
            else
                h = mid;
        }
        return l;
    }
};

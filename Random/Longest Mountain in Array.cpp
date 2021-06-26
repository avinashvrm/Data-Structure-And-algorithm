class Solution {
public:
    int longestMountain(vector<int>& arr)
    {
        int n = arr.size();
        int res = 0;
        for(int i=1;i<n;i++)
        {
            int cnt = 1;
            int j=i;
            bool flag = false;
            while(j<n && arr[j] > arr[j-1])
            {
                j++;
                cnt++;
            }
            while(i!=j && j<n && arr[j] < arr[j-1])
            {
                j++;
                cnt++;
                flag=true;
            }
            if(cnt>2 && flag){
                res = max(res,cnt);
                j--;
            }
            i=j;
        }
        return res;
        
    }
};

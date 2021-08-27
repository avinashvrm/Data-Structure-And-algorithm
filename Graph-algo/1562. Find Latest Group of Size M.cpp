//https://leetcode.com/problems/find-latest-group-of-size-m/
class Solution {
public:
    int find(vector<int> &par, int i) {
        while(par[i] != i) {
            par[i] = par[par[i]];
            i = par[i];
        }
        return i;
    }
    void union_bysz(int a, int b, vector<int>& sz, vector<int> &par, unordered_map<int,int> &cnt) {
        // Merging B into A
        int parA = find(par, a);
        int parB = find(par, b);
        
        if (parA == parB) return;
        
        par[parB] = parA;
        cnt[sz[parA]]--;
        cnt[sz[parB]]--;
        sz[parA] += sz[parB];
        cnt[sz[parA]]++;
        sz[parB] = 0;
        
    }
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        int ans = -1;
        vector<int> par(n, 0);
        for(int i=0; i<n; i++) par[i] = i;
        
        vector<int> sz(n, 0);
        string s(n, '0');
        
        unordered_map<int, int> cnt;
        
        for(int i=0; i<n; i++) 
        {
            arr[i]--;
            sz[arr[i]]++;
            cnt[sz[arr[i]]]++;
            s[arr[i]] = '1';
            
            if (arr[i] != 0 && s[arr[i]-1] == '1') {
                union_bysz(arr[i], arr[i]-1, sz, par, cnt);
            }
            if (arr[i] < n-1 && s[arr[i]+1] == '1') {
                union_bysz(arr[i], arr[i]+1, sz, par, cnt);
            }
            if (cnt[m] > 0) {ans = i+1;}
        }
        return ans;
    }
};

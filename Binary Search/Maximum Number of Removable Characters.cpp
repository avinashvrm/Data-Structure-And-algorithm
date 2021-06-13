/*1898. Maximum Number of Removable Characters
You are given two strings s and p where p is a subsequence of s. You are also given a distinct 0-indexed integer array removable containing a subset of indices of s (s is also 0-indexed).

You want to choose an integer k (0 <= k <= removable.length) such that, after removing k characters from s using the first k indices in removable, p is still a subsequence of s. More formally, you will mark the character at s[removable[i]] for each 0 <= i < k, then remove all marked characters and check if p is still a subsequence.

Return the maximum k you can choose such that p is still a subsequence of s after the removals.
Input: s = "abcacb", p = "ab", removable = [3,1,0]
Output: 2
*/
class Solution {
public:
    bool solve(string s, string p, vector<int>& rem,int k)
    {
        for(int i=0;i<k;i++)
            s[rem[i]] = '#';
        
        int n1 = s.size();
        int n2 = p.size();
        int i=0,j=0;
        while(i<n1 && j<n2)
        {
            if(s[i]==p[j])
            {
                i++;
                j++;
            }
            else
                i++;
        }
        return j==n2;
        
    }
    int maximumRemovals(string s, string p, vector<int>& rem) 
    {
        int i = 0;
        int j = rem.size();
        int res = 0;
        
        while(i<=j)
        {
            int mid = (i+j)/2;
            
            if(solve(s,p,rem,mid))
            {
                res = mid;
                i = mid+1;
            }
            else
                j = mid-1;
            cout<<mid<<"  ";
        }
        return res;
    }
};

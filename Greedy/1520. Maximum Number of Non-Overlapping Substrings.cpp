/*Input: s = "adefaddaccc"
Output: ["e","f","ccc"]
Explanation: The following are all the possible substrings that meet the conditions:
[
  "adefaddaccc"
  "adefadda",
  "ef",
  "e",
  "f",
  "ccc",
]
If we choose the first string, we cannot choose anything else and we'd get only 1. If we choose "adefadda", we are left with "ccc" which is the only one that doesn't overlap, thus obtaining 2 substrings. Notice also, that it's not optimal to choose "ef" since it can be split into two. Therefore, the optimal way is to choose ["e","f","ccc"] which gives us 3 substrings. No other solution of the same number of substrings exist.
Example 2:

Input: s = "abbaccd"
Output: ["d","bb","cc"]
Explanation: Notice that while the set of substrings ["d","abba","cc"] also has length 3, it's considered incorrect since it has larger total length.*/

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        
        vector<int> fst(26, INT_MAX);
        vector<int> lst(26, INT_MIN);
        for (int i = 0; i < n; i++) {
            fst[s[i] - 'a'] = min(fst[s[i] - 'a'], i);
            lst[s[i] - 'a'] = max(lst[s[i] - 'a'], i);
        }
        
        vector<pair<int, int>> t;
        for (int i = 0; i < 26; i++) {
            if (fst[i] < n) {
                int b = fst[i];
                int e = lst[i];
                for (int j = b; j <= e; j++) {
                    b = min(b, fst[s[j] - 'a']);
                    e = max(e, lst[s[j] - 'a']);
                }
                if (b == fst[i]) {
                    t.emplace_back(e, b);
                }
            }
        }
        
        sort(t.begin(), t.end());
        vector<string> ans;
        int prev = -1;
        for (auto &[e, b] : t) {
            if (b > prev) {
                ans.push_back(s.substr(b, e - b + 1));
                prev = e;
            }
        }
        
        return ans;
    }
};

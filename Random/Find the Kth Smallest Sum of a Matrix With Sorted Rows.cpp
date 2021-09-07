/*https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/
You are given an m * n matrix, mat, and an integer k, which has its rows sorted in non-decreasing order.

You are allowed to choose exactly 1 element from each row to form an array. Return the Kth smallest array sum among all possible arrays.

Example 1:
Input: mat = [[1,3,11],[2,4,6]], k = 5
Output: 7
Explanation: Choosing one element from each row, the first k smallest sum are:
[1,2], [1,4], [3,2], [3,4], [1,6]. Where the 5th sum is 7.  

Example 2:
Input: mat = [[1,3,11],[2,4,6]], k = 9
Output: 17

Example 3:
Input: mat = [[1,10,10],[1,4,5],[2,3,6]], k = 7
Output: 9
Explanation: Choosing one element from each row, the first k smallest sum are:
[1,1,2], [1,1,3], [1,4,2], [1,4,3], [1,1,6], [1,5,2], [1,5,3]. Where the 7th sum is 9.  

Example 4:
Input: mat = [[1,1,10],[2,2,9]], k = 7
Output: 12
*/
class Solution {  
 public:  
      int kthSmallest(vector<vector<int>>& mat, int k)
      {  
            set< pair<int, vector<int>>> s;
            pair<int,vector<int>> vec;// vector is storing the index of the elements for each row
            for(int i=0;i<mat.size();i++)
            {
                vec.second.push_back(0);
                vec.first+=mat[i][0];
            }
            s.insert(vec);
            if(k==1){
                return vec.first;
            }
            while(k>1)
            {
                auto itr = s.begin();
                pair<int, vector<int> > a = (*itr);
                s.erase(itr);
                for(int i=0;i<mat.size();i++)
                {
                    if(a.second[i]+1 < mat[i].size())
                    {
                        a.first +=  mat[i][a.second[i]+1] - mat[i][a.second[i]];//idea is- ek ek kar ke har row ke next element ko add krna(bakiyo ko vaese hi rkh kr)
                        a.second[i]++;
                        s.insert(a);// first we added the next and del prev, now we inserting that in out set
                        a.second[i]--;// a ko vaps retrive kr rhe next row m same kam krne ke liye
                        a.first += mat[i][a.second[i]] - mat[i][a.second[i]+1];//Thoda sa bfs vala feel h isme

                    }
                }
                k--;
            }
            auto temp = s.begin();
            int ans= (*temp).first;
            return ans;
      }  
 };  

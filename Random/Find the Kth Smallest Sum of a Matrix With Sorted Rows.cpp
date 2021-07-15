//https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/
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

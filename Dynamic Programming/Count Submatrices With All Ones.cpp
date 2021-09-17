/*
https://www.youtube.com/watch?v=hrd-MEcZkOI&ab_channel=CodingBeast   [Explanation]
logic : start with 1D array and think about how to solve for 2D array(for each cell)

Given a rows * columns matrix mat of ones and zeros, return how many submatrices have all ones.

 

Example 1:

Input: mat = [[1,0,1],
              [1,1,0],
              [1,1,0]]
Output: 13
Explanation:
There are 6 rectangles of side 1x1.
There are 2 rectangles of side 1x2.
There are 3 rectangles of side 2x1.
There is 1 rectangle of side 2x2. 
There is 1 rectangle of side 3x1.
Total number of rectangles = 6 + 2 + 3 + 1 + 1 = 13.
Example 2:

Input: mat = [[0,1,1,0],
              [0,1,1,1],
              [1,1,1,0]]
Output: 24
Explanation:
There are 8 rectangles of side 1x1.
There are 5 rectangles of side 1x2.
There are 2 rectangles of side 1x3. 
There are 4 rectangles of side 2x1.
There are 2 rectangles of side 2x2. 
There are 2 rectangles of side 3x1. 
There is 1 rectangle of side 3x2. 
Total number of rectangles = 8 + 5 + 2 + 4 + 2 + 2 + 1 = 24.
Example 3:

Input: mat = [[1,1,1,1,1,1]]
Output: 21
*/

class Solution {
public:
   
    int numSubmat(vector<vector<int>>& mat) 
    {
        //nai hua
        int r = mat.size();
        int c = mat[0].size();
        vector<vector<int>> vec(r,vector<int>(c,0));
        for(int i=0;i<r;i++)
        {
            int one = 0;
            for(int j=c-1;j>=0;j--)
            {
                if(mat[i][j]==1)
                {
                    one++;
                    vec[i][j] = one;
                }
                else
                {
                    one = 0;
                    vec[i][j]=one;
                }
            }
        }
        int res = 0;
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                //cout<<vec[i][j]<<" ";
                if(vec[i][j])
                {
                    int k = vec[i][j];
                    for(int h = i; h<r; h++)
                    {
                        k = min(vec[h][j],k);
                        res+= k;
                    }
                }
                
            }
            //cout<<endl;
        }
        return res;
        
    }
};

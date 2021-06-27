class Solution {
public:
    //function to rate the layer by k times (array rotation concept)
    void rotate(vector<int>&temp,int k)
    {
        int n=temp.size();
        k = k%n;
        reverse(temp.begin(),temp.end());
        reverse(temp.begin(),temp.begin()+n-k);
        reverse(temp.begin()+n-k,temp.end());
    }
    //function to 
    void layer_and_solve(vector<vector<int>>grid,vector<vector<int>>&ans,int r1,int r2,int c1,int c2,int k)
    {
        // get each layer wrt the botrder of the array(spiral concept)
        vector<int>temp;
        
        for(int c=c1; c<=c2; c++)
            temp.push_back(grid[r1][c]);
        
        for(int r = r1+1; r<=r2; r++)
            temp.push_back(grid[r][c2]);
        
        if(r1<r2 && c1<c2)
        {
            for(int c=c2-1;c>=c1;c--)
                temp.push_back(grid[r2][c]);
            
            for(int r=r2-1;r>r1;r--)
                temp.push_back(grid[r][c1]);
        }
        //rotate the layer
        rotate(temp,k);
        int i=0;
        // put the rotated value of the layer into the answer(spiral concept)
        for(int c=c1;c<=c2;c++)
            ans[r1][c]=temp[i++];
        
        for(int r=r1+1;r<=r2;r++)
            ans[r][c2]=temp[i++];
        
        if(r1<r2&&c1<c2)
        {
            for(int c=c2-1;c>=c1;c--)
                ans[r2][c]=temp[i++];
            for(int r=r2-1;r>r1;r--)
                ans[r][c1]=temp[i++];
        }
    }
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k)
    {
        vector<vector<int>>ans(grid.size(),vector<int>(grid[0].size(),0));
        
        int left=0;
        int bottom = grid.size()-1;
        int top=0;
        int right = grid[0].size()-1;
        
        while(top <= bottom && left <= right)
        {
            layer_and_solve(grid,ans,top,bottom,left,right,k);
            //modify the values for accessing the next layer.
            top++;
            left++;
            bottom--;
            right--;  
        }
        return ans;
    }
};

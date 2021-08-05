//video solution- https://www.youtube.com/watch?v=-sd55qo_8Zg

class Solution {
public:
    pair<int,int> par[501][501];
    int rank[501][501];
    
    pair<int,int> find_opr(pair<int,int> a){
        if(par[a.first][a.second]==a){
            return a;
        }
        return par[a.first][a.second]=find_opr(par[a.first][a.second]);
    }
    
    void union_opr(pair<int,int> a,pair<int,int> b){
        a=find_opr(a);
        b=find_opr(b);
        if(rank[a.first][a.second]>rank[b.first][b.second]){
            par[b.first][b.second]=a;
            rank[a.first][a.second]++;
        }
        else{
            par[a.first][a.second]=b;
            rank[b.first][b.second]++;
        }
    }
    
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                par[i][j]={i,j};
                rank[i][j]=1;
            }
        }
        
        for(int i=0;i<n;i++){
            unordered_map<int,pair<int,int>> mp;
            for(int j=0;j<m;j++){
                if(mp.find(mat[i][j])!=mp.end()){
                    union_opr({i,j},mp[mat[i][j]]);
                }
                else{
                    mp[mat[i][j]]={i,j};
                }
            }
        }
        
        for(int j=0;j<m;j++){
            unordered_map<int,pair<int,int>> mp;
            for(int i=0;i<n;i++){
                if(mp.find(mat[i][j])!=mp.end()){
                    union_opr({i,j},mp[mat[i][j]]);
                }
                else{
                    mp[mat[i][j]]={i,j};
                }
            }
        }
        
        vector<pair<int,int>> v[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pair<int,int> x=find_opr({i,j});
                v[x.first][x.second].push_back({i,j});
            }
        }
        
        map<int,vector<vector<pair<int,int>>>> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j].size()!=0){
                    mp[mat[i][j]].push_back(v[i][j]);
                }
            }
        }
        
        vector<vector<int>> ans(n,vector<int>(m,0));
        vector<int> row(n,0),col(m,0);
        for(auto x:mp){
            auto list=x.second;
            for(auto y:list){
                int max1=0;
                for(auto z:y){
                    max1=max(max1,max(row[z.first],col[z.second])+1);
                }
                for(auto z:y){
                    ans[z.first][z.second]=max1;
                    row[z.first]=max(max1,row[z.first]);
                    col[z.second]=max(max1,col[z.second]);
                }
            }
        }
        
        
        return ans;
    }
};

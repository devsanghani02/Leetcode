class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
    return -1;
        
       vector<vector<int>> dis(n,vector<int>(n,INT_MAX));
       dis[0][0]=1;
       queue<pair<int,pair<int,int>>> q;
       q.push({1,{0,0}});
       int dr[]={-1,-1,0,1,1,1,0,-1};
       int dc[]={0,-1,-1,-1,0,1,1,1};

       while(!q.empty()){
        int r=q.front().second.first;
        int c=q.front().second.second;
        int wt=q.front().first;
        q.pop();
        for(int i=0;i<8;i++){
            int row=r+dr[i];
            int col=c+dc[i];
            if(row>=0 && col>=0 && row<n && col<n
            && wt+1<dis[row][col] && grid[row][col]==0){
                   q.push({wt+1,{row,col}});
                   dis[row][col]=wt+1;
            }
        }
       

       }
       if(dis[n-1][n-1]==INT_MAX) return -1;
       else return dis[n-1][n-1];
    }
};
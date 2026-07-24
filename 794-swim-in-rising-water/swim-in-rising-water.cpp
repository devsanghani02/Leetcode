class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
       
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        vector<vector<int>> vis(n,vector<int>(n,0));
        q.push({grid[0][0],{0,0}});
        
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        int ans=0;
        vis[0][0]=1;
        while(!q.empty()){
            auto x=q.top();
            q.pop();
            int t=x.first;
            int row=x.second.first;
            int col=x.second.second;
            ans=max(ans,t);
            if(row==(n-1) && col==(n-1)){
                break;
            }
            
            for(int i=0;i<4;i++){
                int r=dr[i]+row;
                int c=dc[i]+col;
                if(r>=0 && c>=0 && r<n && c<n && !vis[r][c]){
                    vis[r][c]=1;
                q.push({grid[r][c],{r,c}});
                }
                
                
                
            }

        }
        return ans;

    }
};
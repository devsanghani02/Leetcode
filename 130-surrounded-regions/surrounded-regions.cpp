class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || i==(n-1) || j==0 || j==(m-1)) && board[i][j]=='O'){
                    vis[i][j]=1;
                    q.push({i,j});
                }else vis[i][j]=0;
            }
        }
        int nr[]={-1,0,1,0};
        int nc[]={0,-1,0,1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int dr=r+nr[i];
                int dc=c+nc[i];
                if(dr>=0 && dc>=0
                && dr<n && dc<m && !vis[dr][dc] && board[dr][dc]=='O'){
                    vis[dr][dc]=1;
                    q.push({dr,dc});
                }
            }

        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    vis[i][j]=1;
                    board[i][j]='X';
                }
            }
        }


    }
};
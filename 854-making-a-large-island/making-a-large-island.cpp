class Disjointset{
public:
    vector<int> par,size;

    Disjointset(int n){
        par.resize(n+1,0);
        size.resize(n+1,0);
        for(int i=0;i<=n;i++){
            par[i]=i;
            size[i]=1;
        }
    }

    int fup(int node){
        if(node==par[node]) return node;
        return par[node]=fup(par[node]);
    }

    void ubs(int u,int v){
        int upu=fup(u);
        int upv=fup(v);

        if(upu==upv) return;

        if(size[upu]>size[upv]){
            par[upv]=upu;
            size[upu]+=size[upv];
        }
        else if(size[upu]<size[upv]){
            par[upu]=upv;
            size[upv]+=size[upu];
        }
        else{
            par[upu]=upv;
            size[upv]+=size[upu];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();

        Disjointset ds(n*n);

        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j]==0) continue;

                for(int k=0;k<4;k++){

                    int row=i+dr[k];
                    int col=j+dc[k];

                    if(row>=0 && col>=0 && row<n && col<n && grid[row][col]==1){

                        int node=i*n+j;
                        int adjnode=row*n+col;

                        ds.ubs(node,adjnode);
                    }
                }
            }
        }

        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j]==0){

                    set<int> s;

                    for(int k=0;k<4;k++){

                        int row=i+dr[k];
                        int col=j+dc[k];

                        if(row>=0 && col>=0 && row<n && col<n && grid[row][col]==1){

                            int node=row*n+col;
                            s.insert(ds.fup(node));
                        }
                    }

                    int mx=0;

                    for(auto it:s)
                        mx+=ds.size[it];

                    ans=max(ans,mx+1);
                }
            }
        }
        for(int cell=0;cell<n*n;cell++){
            ans=max(ans,ds.size[ds.fup(cell)]);
        }

        return ans;
    }
};
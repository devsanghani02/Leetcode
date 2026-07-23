class Solution {
     class Disjointset{
        vector<int> rank,par;
public:
    Disjointset(int n){
        rank.resize(n+1,0);
        par.resize(n+1,0);
        for(int i=0;i<=n;i++){
            par[i]=i;
        }
    }
    int fup(int node){
              if(node==par[node]) return node;
              return par[node]=fup(par[node]);
    }
    void ubr(int u,int v){
        int upu=fup(u);
        int upv=fup(v);
        if(upu==upv) return;
        if(rank[upu]<rank[upv]){
            par[upu]=upv;
        }else if(rank[upv]<rank[upu]){
            par[upv]=upu;
        }else{
            par[upu]=upv;
            rank[upv]++;
        }
    }
     };
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int x=isConnected.size();
        Disjointset ds(x);
        
        for(int i=0;i<x;i++){
            for(int j=0;j<isConnected[0].size();j++){
                if(isConnected[i][j]==1){
                    ds.ubr(i,j);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<x;i++){
            if(ds.fup(i)==i) cnt++;
        }
        return cnt;
        
    }
};
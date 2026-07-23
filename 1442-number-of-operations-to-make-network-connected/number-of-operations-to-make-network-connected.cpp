class Solution {
    class Disjointset{
        vector<int> par,rank;
public:
    Disjointset(int n){
        par.resize(n+1,0);
        rank.resize(n+1,0);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }

    int fup(int node){
        if(par[node]==node) return node;
        return par[node]=fup(par[node]);
    }

    void ubr(int u,int v){
        int upu=fup(u);
        int upv=fup(v);
        if(upu==upv) return;
        if(rank[upu]>rank[upv]){
            par[upv]=upu;
        }else if(rank[upu]<rank[upv]){
            par[upu]=upv;
        }else{
            par[upv]=upu;
            rank[upu]++;
        }
    }


    };
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        Disjointset ds(n);
        /*
        vector<vector<int>> adj(n);
        
        for(auto it:connections){
            adj[it[0]].push_back(it[0]);
            adj[it[1]].push_back(it[0]);

        }
        */
        int cnt=0;
        
        for(auto it: connections){
          
            ds.ubr(it[0],it[1]);
            
            
            
        }
        for(int i=0;i<n;i++){
            if(ds.fup(i)==i) cnt++;
        }
        
        
        
        return cnt-1;

    }
};
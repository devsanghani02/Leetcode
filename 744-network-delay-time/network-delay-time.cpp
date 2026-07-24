class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it: times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,k});
        vector<int> dis(n+1,1e9);
        dis[k]=0;
        dis[0]=0;
        
        
        while(!q.empty()){
             auto x=q.top();
             q.pop();
             int node=x.second;
             int wt=x.first;
             if(wt>dis[node]) continue;
           
             for(auto it: adj[node]){
                int ex=it.second;
                int v=it.first;
                   if(ex+wt<dis[v]){
                   dis[v]=ex+wt;
                   q.push({dis[v],v});
                   }
             }
        }
        for(int i=0;i<=n;i++){
            if(dis[i]==1e9) return -1;
        }
        int ans=0;
        for(int i=0;i<=n;i++){
            if(ans<dis[i]) ans=dis[i];
        }
        return ans;
        
    }
};
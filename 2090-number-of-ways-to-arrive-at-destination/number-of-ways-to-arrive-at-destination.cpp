class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});

        }
        vector<long long> dis(n,LLONG_MAX);
        int mod=1e9 +7;
        priority_queue<
pair<long long,int>,
vector<pair<long long,int>>,
greater<pair<long long,int>>
> q;
        q.push({0,0});
        dis[0]=0;
        vector<int> ways(n,0);
        ways[0]=1;
        while(!q.empty()){
            auto it=q.top();
            long long d=it.first;
            long long node=it.second;
            
            q.pop();
            if(d>dis[node]) continue;
            for(auto it: adj[node]){
                
                long v=it.first;
                long wt=it.second;
                
               
                

                if(d+wt<dis[v]){
                    ways[v]=ways[node];
                   
                    dis[v]=d+wt;
                    q.push({dis[v],v});
                    
                }
                else if(d+wt==dis[v]){
                ways[v]=(ways[v]+ways[node])%mod;
               }
                
                
            }
        }
        return ways[n-1];
    }
};
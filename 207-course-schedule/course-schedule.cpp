class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        
        
        if(prerequisites.empty()) return true;
        vector<vector<int>> adj(numCourses);
        for(auto &it:prerequisites){
            int u=it[0];
            int v=it[1];
            adj[v].push_back(u);
        }
        vector<int> ind(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto j: adj[i]){
                ind[j]++;
            }
        }
        queue<int> q;
        int cnt=0;
        for(int i=0;i<numCourses;i++){
            if(ind[i]==0){
                
                q.push(i);
            }
            
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;
            for(auto it:adj[node]){
                ind[it]--;
                if(ind[it]==0) q.push(it);
                
            }
        }
        if(cnt==numCourses) return true;
        return false;
    }
};
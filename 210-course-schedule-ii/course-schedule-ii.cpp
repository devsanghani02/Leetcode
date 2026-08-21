class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        int n=pre.size();
        vector<vector<int>> adj(num);
        vector<int> ans;
        for(auto it: pre){
            adj[it[1]].push_back(it[0]);

        }
        vector<int> ind(num,0);
        for(int i=0;i<num;i++){
            for(auto it:adj[i]){
                ind[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<num;i++){
            if(ind[i]==0){
                q.push(i);
            }
        }
        int cnt=0;
        while(!q.empty()){
          int node=q.front();
          q.pop();
          ans.push_back(node);
          cnt++;
          for(auto it: adj[node]){
            ind[it]--;
            if(ind[it]==0) q.push(it);
          }
        }
        if(num!=cnt){
            ans.clear();
            return ans;
        }
        return ans;
        


    }
};
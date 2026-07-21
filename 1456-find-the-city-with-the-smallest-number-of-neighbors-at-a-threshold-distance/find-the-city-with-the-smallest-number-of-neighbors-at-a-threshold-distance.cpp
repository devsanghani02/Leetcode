class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dis(n,vector<int>(n,1e9));
        for(auto it : edges){
            dis[it[0]][it[1]]=it[2];
            dis[it[1]][it[0]]=it[2];

            
        }
        for(int i=0;i<n;i++){
            for(int k=0;k<n;k++){
                if(i==k){
                    dis[i][k]=0;
                }
            
        }
    }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            
        }
            
        }

        }
        
    int ans=INT_MAX;
    int ind=0;
        for(int i=0;i<n;i++){
            int cnt=0;
            
            for(int k=0;k<n;k++){
                if(dis[i][k]<=distanceThreshold && dis[i][k]>0){
                    cnt++;
                    
                }
            
        }
        if(ans>=cnt){
            ans=cnt;
             ind=i;
        }
        }
        
        return ind;
}
};
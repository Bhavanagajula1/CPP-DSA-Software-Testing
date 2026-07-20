class Solution {
public:
void dfs(int node, vector<vector<int>>&adjList,vector<int>&vis){
    vis[node]=1;
    for(auto it:adjList[node]){
        if(!vis[it]){
            dfs(it,adjList,vis);
        }
    }
}
    int findCircleNum(vector<vector<int>>&adj) {
     int n=adj.size();
     vector<vector<int>>adjList(n);
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(adj[i][j]==1&& 1!=j){
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
     }  
     vector<int>vis(n,0);
     int cnt=0;
     for(int i=0;i<n;i++){
        if(!vis[i]){
            cnt++;
            dfs(i,adjList,vis);
        }
     }
        return cnt;
    }
};
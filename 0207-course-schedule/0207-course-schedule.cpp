class Solution {
public:
    bool dfs(unordered_map<int , vector<int>>&adj,int u,vector<bool>&visited , vector<bool>&inRecurrsion){
        visited[u] = true;
        inRecurrsion[u] = true;
        for(auto &v : adj[u]){
            if(!visited[v] && dfs(adj,v,visited,inRecurrsion) ){
                return true;
            }
            else if(inRecurrsion[v] == true){
                return true;
            }
        }
        inRecurrsion[u] = false;
        return false;
        
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int , vector<int>>adj;
        // vector<int>inDegree(numCourses , 0);
        for(auto ele : prerequisites){
            int u = ele[1];
            int v = ele[0];
            adj[u].push_back(v);

            // inDegree[v]++;
        }

        

        // for(int u = 0 ; u < numCourses ; u++){
        //     for(auto &v : adj[u]){
        //         inDegree[v]++;
        //     }
        // }
        // int cnt = 0;
        // queue<int>q;
        // for(int i = 0 ; i < inDegree.size() ;i++){
        //     if(inDegree[i] == 0){
        //         q.push(i);
        //         cnt++;
        //     }
        // }

        
        // while(!q.empty()){
        //     int u = q.front();
        //     q.pop();

        //     for(auto &v : adj[u]){
        //         inDegree[v]--;
        //         if(inDegree[v] == 0){
        //             q.push(v);
        //             cnt++;
        //         }
        //     }
        // }

        // return cnt == adj.size();
        vector<bool>visited(numCourses , false);
        vector<bool>inRecurrsion(numCourses , false);
        stack<int>st;
        for(int i = 0 ; i < numCourses ; i++){
            if(!visited[i] && dfs(adj,i,visited,inRecurrsion)){
                return false;
            }
        }
        return true;

        

    }


};
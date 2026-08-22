class Solution {
public:
    bool isCycle;
    void DFS(unordered_map<int , vector<int>>&adj , int u , vector<bool>&visited , vector<bool>&inRecurrsion , stack<int>&st){
        visited[u] = true;
        inRecurrsion[u] = true;
        for(auto &v : adj[u]){
            if(inRecurrsion[v] == true){
                isCycle = true;
                return;
            }
            if(!visited[v]){
                DFS(adj,v,visited,inRecurrsion,st);
            }
        }
        st.push(u);
        inRecurrsion[u] = false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
      /*  vector<int>ans;
        unordered_map<int,vector<int>>adj;
        int n =  prerequisites.size();
        vector<int>inDegree(numCourses,0);
        for(int i = 0 ; i < n ; i++){
            for(auto &ele : prerequisites){
                int u = ele[1];
                int v = ele[0];
                adj[u].push_back(v);

                inDegree[v]++;

            }
        }

        queue<int>q;
        int cnt = 0;
        for(int i = 0 ; i < inDegree.size() ; i++){
            if(inDegree[i] == 0){
                q.push(i);
                cnt++;
            }
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for(int &v : adj[u]){
                inDegree[v]--;
                if(inDegree[v] == 0){
                    q.push(v);
                    cnt++;
                }
            }
        }
        if(cnt == numCourses){
            return ans;
        } else {
            return {};
        }*/

        unordered_map<int , vector<int>>adj;
        int n = prerequisites.size();

        
        for(auto &ele : prerequisites){
            int u = ele[1];
            int v = ele[0];

            adj[u].push_back(v);
        }
    

        isCycle = false;
        vector<bool>visited(numCourses , false);
        vector<bool>inRecurrsion(numCourses , false);
        stack<int>st;

        for(int i = 0 ; i < numCourses ; i++){
            if(!visited[i]){
                DFS(adj , i , visited , inRecurrsion , st);
            }
        }
        
        vector<int> result;
        if(isCycle == true){
            return {};
        }
        else {
            while(!st.empty()){
                result.push_back(st.top());
                st.pop();
            }
        }
        return result;












    } 
};
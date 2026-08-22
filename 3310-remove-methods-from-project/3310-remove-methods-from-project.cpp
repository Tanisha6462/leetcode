class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_map<int , vector<int>>adj;
        vector<int>ans;
        
        for(auto &i : invocations){
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
        }
        queue<int>q;
        vector<bool>s(n , false);
        
        q.push(k);
        s[k] = true;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto &v : adj[node]){
                if(!s[v]){
                    q.push(v);
                    s[v] = true;
                }
            }
        }

        for(auto &i : invocations){
            int u = i[0];
            int v = i[1];
            if(!s[u] && s[v]){
                vector<int> ans;
                for (int i = 0; i < n; i++) {
                    ans.push_back(i);
                }
               return ans;
            }
        }
        

        for(int i = 0 ; i < n ; i++){
            if(s[i] == false){
                ans.push_back(i);
            }        

        }

        return ans;

    }
};
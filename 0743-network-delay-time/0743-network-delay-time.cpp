class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int , vector<pair<int , int>>>adj;
        for(auto &time : times){
            int u = time[0];
            int v = time[1];
            int d = time[2];
            adj[u].push_back({v,d});
        }
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int> result(n+1, INT_MAX);
        result[k] = 0;
        pq.push({0,k});

        while(!pq.empty()){
            int node = pq.top().second;
            int dist = pq.top().first;  
            pq.pop();

            if(dist > result[node]){
                continue;
            }

            for(auto &v : adj[node]){
                int d = v.second;
                int adjNode = v.first;

                if(d + dist < result[adjNode]){
                    result[adjNode] = d + dist;
                    pq.push({d+dist , adjNode});
                }
            }
        }
        int minTime = 0;
        for(int i = 1 ; i < result.size() ; i++){
            if(result[i] == INT_MAX){
                return -1;
            }
            minTime = max(minTime , result[i] );
        }

        return minTime;

    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_map<int , vector<pair<int , int>>>adj;
        int n = points.size();
        for(int i = 0 ; i < n ; i++){
            for(int j = i + 1 ; j < n ; j++){
                int cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({j,cost});
                adj[j].push_back({i,cost});
            }
        }

        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>>pq;
        int sum = 0;
        vector<bool>visited(n,false);

        pq.push({0,0});
        while(!pq.empty()){
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            if(visited[node]){
                continue;
            }
            sum += wt;
            visited[node] = true;

            for(auto &v : adj[node]){
                int adjNode = v.first;
                int adjCost = v.second;
                if(!visited[adjNode]){
                    pq.push({adjCost , adjNode});
                }
            }

        }
        return sum;
    }
};
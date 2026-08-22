class Solution {
public:
    bool isSafe(int x , int y , int m , int n){
        if(x >= 0 && x < m && y >= 0 && y < n){
            return true;
        }
        return false;
    }
    typedef pair<int , pair<int , int>> P;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>>directions = {{0,1},{-1,0},{0,-1},{1,0}};
        if(m == 0 || n == 0){
            return -1;
        }

        priority_queue< P , vector<P> , greater<P>>pq;
        vector<vector<int>>result(m , vector<int>(n , INT_MAX));

        result[0][0] = 0;
        pq.push({0,{0,0}});

        while(!pq.empty()){
            int diff = pq.top().first;
            auto coordinate = pq.top().second;
            int x = coordinate.first;
            int y = coordinate.second;
            pq.pop();

            if(result[x][y] < diff){
                continue;
            }

            if( x == m-1 && y == n-1){
                return diff;
            }

            for(auto &dir : directions){
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if(isSafe(x_,y_,m,n)){
                    int absdiff = abs(heights[x_][y_] - heights[x][y]);
                    
                    if(max(absdiff , diff) < result[x_][y_]){
                        result[x_][y_] = max(absdiff , diff);
                        pq.push({max(absdiff , diff) , {x_,y_}});
                    }
                    // if(absdiff > Diff && absdiff < result[x_][y_]){
                    //     result[x_][y_] = diff;
                    //     q.push({diff , {x_,y_}});
                    // }
                }
            }

        }

        return result[m-1][n-1];


    }
};
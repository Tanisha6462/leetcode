class Solution {
public:
    
    int n;
    // int solve(vector<vector<int>>& pairs,int i , int p){
    //     if(i >= n){
    //         return 0;
    //     }
    //     if(p != -1 && t[i][p] != -1){
    //         return t[i][p];
    //     }
    //     int skip = solve(pairs,i+1,p);
    //     int take = 0;
    //     if(p == -1 || pairs[p][1] < pairs[i][0]){
    //         take = 1 + solve(pairs , i+1 , i);
    //     }
    //     if(p != -1){
    //         t[i][p] = max(take , skip);
    //     }
    //     return max(take , skip);
    // }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        vector<int>t(pairs.size(),1);
        int maxLen = 1;
        for(int i = 1 ; i < pairs.size() ;i++){
            for(int j = 0 ; j < i ; j++){
                if(pairs[j][1] < pairs[i][0]){
                    t[i] = max(1 + t[j] , t[i]);
                    maxLen = max(maxLen , t[i]);
                }
            }
        }
        return t[pairs.size()-1];
    }
};
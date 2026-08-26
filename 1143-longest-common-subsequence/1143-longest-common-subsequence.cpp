class Solution {
public:
    // vector<vector<int>>t;
    // int m  , n;
    // int solve(string s1 , string s2 , int i , int j){
    //     if(i >= m || j >= n){
    //         return 0;
    //     }
    //     if(t[i][j] != -1){
    //         return t[i][j];
    //     }
    //     if(s1[i] == s2[j]){
    //         return t[i][j] = 1 + solve(s1,s2,i+1,j+1);
    //     }
        
    //     return  t[i][j] = max(solve(s1,s2,i+1,j) , solve(s1,s2,i,j+1));
        
    // }
    int longestCommonSubsequence(string text1, string text2) {
        // m = text1.length();
        // n = text2.length();
        // t = vector<vector<int>>(m+1 , vector<int>(n+1,-1))
        // return solve(text1,text2,0,0);

        int m = text1.size();
        int n = text2.size();
        vector<vector<int>>t(m+1,vector<int>(n+1,0));
        for(int i = 1 ; i <= m ; i++){
            for(int j = 1 ; j <= n ; j++){
                if(text1[i-1] == text2[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else {
                    t[i][j] = max(t[i][j-1] , t[i-1][j]);
                }
            }
        }
        return t[m][n];
    }
};
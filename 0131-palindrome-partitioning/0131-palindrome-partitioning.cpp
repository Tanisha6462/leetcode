class Solution {
public:
    // bool isPalindrome(string s , int start , int end){
    //     if(start >= end){
    //         return true;
    //     }

    //     if(s[start] != s[end]){
    //         return false;
    //     }
    //     else {
    //         return isPalindrome(s,start+1,end-1);
    //     }
    // }
    // void backtrack(string s , int indx , vector<string>& curr , vector<vector<string>>&result){
    //     if(indx == s.length()){
    //         result.push_back(curr);
    //         return;
    //     }
    //     for(int i = indx ; i < s.length() ; i++){
    //         if(isPalindrome(s,indx ,i)){
    //             curr.push_back(s.substr(indx,i-indx+1));
    //             backtrack(s,i+1,curr,result);
    //             curr.pop_back();
    //         }
    //     }
    // }

    void solve(string &s , int i , vector<vector<string>>& result,vector<string>& curr,vector<vector<int>>&t){
        if(i == s.size()){
            result.push_back(curr);
            return;
        }

        for(int j = i ; j < s.size() ;j++){
            if(t[i][j] == true){
                curr.push_back(s.substr(i,j-i+1));
                solve(s,j+1,result,curr,t);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        // vector<vector<string>>result;
        // vector<string>curr;
        // backtrack(s,0,curr,result);
        // return result;

        int n = s.length();
        vector<vector<int>>t(n , vector<int>(n,false));

        for(int i = 0 ; i < n ; i++){
            t[i][i] = true;
        }

        for(int L = 2 ; L <= n ; L++){
            for(int i = 0 ; i+L-1 < n ;i++){
                int j = i + L - 1;
                if(s[i] == s[j] && L == 2){
                    t[i][j] = true;
                }
                else {
                    t[i][j] = s[i] == s[j] && t[i+1][j-1];
                }
            }
        }

        vector<vector<string>> result;
        vector<string> curr;
        solve(s,0,result,curr,t);
        return result;
    }
};
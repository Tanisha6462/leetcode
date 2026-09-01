class Solution {
public:
    bool solve(string &s , int i , int j){
        if(i >= j){
            return true;
        }
        if(s[i] == s[j]){
            return solve(s , i + 1 , j-1);
        }
        else {
            return false;
        }
    }
    string longestPalindrome(string s) {
        int n = s.length();
        int maxLen = 0;
        int SP = -1;
        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){
                if(solve(s,i,j)){
                    if(j-i+1 > maxLen){
                    maxLen = j-i+1;
                    SP = i;
                    }
                }
            }
        }
        return s.substr(SP,maxLen);
    }
};
class Solution {
public:
    // memoisation
    
    
    bool ispredecessor(string s1 , string s2){
        int m = s1.size();
        int n = s2.size();
        if(n-m != 1){
            return false;
        }
        int i = 0;
        int j = 0;
        while(i < m && j < n){
            if(s1[i] == s2[j]){
                i++;
                j++;
            }
            else {
                j++;
            }
        }
        if( i == m){
            return true;
        }
        else {
            return false;
        }
    }
    /*
    vector<vector<int>>t;
    int n;

    int solve(vector<string>& words , int i , int p){
        if(i >= n){
            return 0;
        }
        if(p != -1 && t[i][p] != -1){
            return t[i][p];
        }
        int skip = solve(words,i+1,p);
        int take = 0;
        if(p == -1 || ispredecessor(words[p] , words[i])){
            take = 1 +  solve(words,i+1,i);
        }
        if(p != -1){
            return t[i][p] = max(skip,take);
        }
        else {
            return max(skip,take);
        }
        
    }*/
    int longestStrChain(vector<string>& words) {
        // n = words.size();
        // t = vector<vector<int>>(n,vector<int>(n,-1));
        sort(words.begin(), words.end(), [](string &a, string &b) {
        return a.size() < b.size();
        });

        vector<int>t(words.size(),1);
        int maxLen = 1;
        for(int i = 1 ; i < words.size() ;i++){
            for(int j = 0 ; j < i ; j++){
                if(ispredecessor(words[j],words[i])){
                    t[i] = max(1+t[j],t[i]);
                    maxLen = max(maxLen , t[i]);
                }
            }
        }
        return maxLen;
    }
};
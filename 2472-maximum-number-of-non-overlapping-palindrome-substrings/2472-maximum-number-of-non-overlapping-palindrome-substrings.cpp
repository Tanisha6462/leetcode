class Solution {
public:
    // int t[20001];
    bool isPalindrome(string s , int i , int j){
        if(i >= j){
            return true;
        }
        if(s[i] != s[j]){
            return false;
        } else {
            return isPalindrome(s,i+1,j-1);
        }
    }
    int solve(string &s , int i , int k){
        if( i >= s.length()){
            return 0;
        }

        // if(t[i] != -1){
        //     return t[i];
        // }
        int ans = solve(s,i+1,k);

        for(int j = i + k - 1 ; j < s.length() ; j++){
            
            if(isPalindrome(s,i,j)){
                ans = max(ans , 1 + solve(s,j+1,k));
            }
        }

        // return t[i] =  
        return ans;
    }
    int maxPalindromes(string s, int k) {
        int n = s.size();
        if (k == 1) return n;

        int res = 0;

        for (int i = 0; i <= n - k;) {
            int step = 1;

            for (int d : {k, k + 1}) {
                if (i + d <= n && equal(s.begin() + i, s.begin() + i + (d >> 1),
                                        s.rbegin() + (n - (i + d)))) {
                    step = d;
                    res++;
                    break;
                }
            }

            i += step;
        }

        return res;
    }
};
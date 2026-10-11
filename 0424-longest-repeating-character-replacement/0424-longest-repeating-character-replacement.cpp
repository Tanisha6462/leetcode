class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char , int>mpp;
        int n = s.length();
        int i = 0;
        int j = 0;
        int ans = 0;
        
        int maxFreq = 0;

        
        while(j < n){
            mpp[s[j]]++;
            
            for (auto it : mpp) {
                maxFreq = max(maxFreq, it.second);
            }

            if((j-i+1) - maxFreq <= k){
                ans = max(ans , j-i+1);
                j++;
            }
            else{
                while((j-i+1)-maxFreq > k){
                    mpp[s[i]]--;
                    if(mpp[s[i]] == 0){
                        mpp.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};
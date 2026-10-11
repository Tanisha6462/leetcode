class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int , int>mpp;
        int ans = 0;
        int n = s.length();
        int i = 0;
        int j = 0;
        while(j < n){
            mpp[s[j]]++;
            if(mpp.size() == j-i+1){
                ans = max(ans,j-i+1);
                j++;
            }
            else{
                while(mpp.size() < j-i+1){
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
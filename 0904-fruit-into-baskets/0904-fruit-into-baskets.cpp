class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int>mpp;
        int i = 0;
        int j = 0;
        int n = fruits.size();
        int ans = 1;
        while(j < n){
            mpp[fruits[j]]++;
            
            if(mpp.size() <= 2){
                ans = max(ans,j-i+1);
                j++;
            }else{
                while(mpp.size() > 2){
                    mpp[fruits[i]]--;
                    if(mpp[fruits[i]] == 0){
                        mpp.erase(fruits[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};
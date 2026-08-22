class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>t(nums.size(),1);
        int maxi = 1;
        for(int i = 1 ; i < nums.size() ;i++){
            
            for(int j = 0 ; j < i ; j++){
                if(nums[j] < nums[i]){
                    t[i] = max(t[j] + 1 , t[i]);
                    
                }
            }
            maxi = max(maxi , t[i]);
            
        }
        return maxi;
    }
};
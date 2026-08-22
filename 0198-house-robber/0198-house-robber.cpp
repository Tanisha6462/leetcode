class Solution {
public:
    int t[101];
    int solve(vector<int>& nums , int i){
        if(i >= nums.size()){
            return 0;
        }
        if(t[i] != -1){
            return t[i];
        }
        int steal = nums[i] + solve(nums,i+2);
        int skip = solve(nums,i+1);
        return t[i] = max(skip , steal);        
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        vector<int>t(n+1);
        t[0] = 0;
        t[1] = nums[0];

        for(int i = 2 ; i <= n ; i++){
            t[i] = max(t[i-2] + nums[i-1] , t[i-1]);
        }
        return t[n];
    }
};
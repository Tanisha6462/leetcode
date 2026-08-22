class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n+1);
        int result1;
        int result2;
        if(n == 1){
            return nums[0];
        }

        if(n == 2){
            return max(nums[0] , nums[1]);
        }

        t[0] = 0;
        t[1] = nums[0];
        for(int i = 2; i <= n-1 ;i++){
            t[i] = max(nums[i-1] + t[i-2] , t[i-1]);
        }
        result1 = t[n-1];

        t.clear();
        t[0] = 0;
        t[1] = 0;
        for(int i = 2; i <= n ;i++){
            t[i] = max(nums[i-1] + t[i-2] , t[i-1]);
        }
        result2 = t[n];

        return max(result1,result2);
    }
};
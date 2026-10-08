class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = INT_MIN;
        int SSF = 0;
        for(int i = 0 ; i < nums.size() ;i++){
            SSF += nums[i];
            sum = max(SSF , sum);
            if(SSF < 0){
                SSF = 0;
            }
        }
        return sum;
    }
};
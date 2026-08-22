class Solution {
public:
    int missingInteger(vector<int>& nums) {
        set<int>st(nums.begin() , nums.end());
        int sum = nums[0];
        for(int j = 1 ; j < nums.size() ; j++){
            if(nums[j] == nums[j-1] + 1){
                sum += nums[j];
            }
            else {
                break;
            }
        }

        while(st.count(sum)){
            sum++;
        }
        return sum;
    }
};
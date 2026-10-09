class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        vector<int>prefix(nums.size());
        prefix[0] = nums[0];
        int ans = 0;
        for(int i = 1 ; i < nums.size() ;i++){
            prefix[i] = prefix[i-1] + nums[i];
        }

        for(int i = 0 ; i < prefix.size() ;i++){
            if(prefix[i] == k){
                ans++;
            }

            if(mpp.find(prefix[i]-k) != mpp.end()){
                ans += mpp[prefix[i]-k];
            }

            mpp[prefix[i]]++;
        }
        return ans;
    }
};
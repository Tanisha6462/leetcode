class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>st;
        for(auto num : nums){
            if(num % k == 0){
                st.insert(num);
            }
        }
        int i = 1;
        while(true){
            if(st.count(k*i) == 0){
                return k*i;
            }
            i = i + 1;
        }
        
    }
};
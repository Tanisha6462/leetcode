class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long odd = 0, even = 0;
        for (int a: nums) {
            even = max(even, odd + a);
            odd = even - a;
        }
        return even;
    }
};
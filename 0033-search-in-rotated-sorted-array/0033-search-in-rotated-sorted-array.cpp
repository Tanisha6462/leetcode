class Solution {
public:
    int minElementIndex(vector<int>& nums){
        int n = nums.size();
        int start = 0;
        int end = n - 1;

        while(start <= end){
            if(nums[start] <= nums[end]){
                return start;
            }

            int mid = start + (end - start)/2;
            int next = (mid+1) % n;
            int prev = (mid + n - 1 ) % n;

            if(nums[mid] < nums[next] && nums[mid] < nums[prev]){
                return mid;
            }
            else if(nums[mid] >= nums[start]){
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return -1;
    }
    int binarySearch(vector<int>& nums, int start , int end , int target){
        end = end - 1;
        while(start <= end){
            int mid = start + (end - start)/2;

            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int indx = minElementIndex(nums);
        int firstHalf = binarySearch(nums,0,indx,target);
        int lastHalf = binarySearch(nums,indx,n,target);

        if (firstHalf != -1) {
            return firstHalf;
        }

        return lastHalf;
    }
};
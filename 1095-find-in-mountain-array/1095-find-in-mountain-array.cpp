/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int maxEleIndex(MountainArray &mountainArr){
    int start = 0;
    int end = mountainArr.length() - 1;

    while(start < end){
        int mid = start + (end - start) / 2;

        if(mountainArr.get(mid) < mountainArr.get(mid + 1)){
            start = mid + 1;
        }
        else{
            end = mid;
        }
    }

        return start;
    }

    int incBinary(int target, MountainArray &mountainArr,int start , int end){
        

        while(start <= end){
            int mid = start + (end - start)/2;

            if(mountainArr.get(mid) == target){
                return mid;
            }
            else if(mountainArr.get(mid) > target){
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return -1;
    }
    int decBinary(int target, MountainArray &mountainArr,int start , int end){
       
        while(start <= end){
            int mid = start + (end - start)/2;

            if(mountainArr.get(mid) == target){
                return mid;
            }
            else if(mountainArr.get(mid) > target){
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        
        int n = mountainArr.length();
        int indx = maxEleIndex(mountainArr);
        int inc = incBinary(target, mountainArr,0 ,indx);
        int dec = decBinary(target, mountainArr,indx+1 ,n-1);

        if(inc != -1){
            return inc;
        }
        else {
            return dec;
        }

    }
};
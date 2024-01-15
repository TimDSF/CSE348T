class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), l = 0, r = n-1; // [_,_] intevals
        
        while (l < r){ // if there are still numbers remaining in the interval
            int m = (l + r) / 2; // find the middle point

            if (nums[m] < target){ // target is larger than the middle point
                l = m + 1; // increase the left end to the right of the middle point
            }else{ // target is the same as or smaller than the middle point
                r = m; // decrease the right end to the middle point
            }
        }
        
        return nums[l] == target ? l : -1; // the position is alawys left end if exist, or would be the position to insert to keep the order
    }
};
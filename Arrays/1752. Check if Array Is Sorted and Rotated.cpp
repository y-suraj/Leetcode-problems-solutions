// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size(), counter = 0;

        int i = 0;
        for(int j=i+1; j<n; j++) {
            if(nums[i] > nums[j]) {
                counter++;
            }
            if(counter > 1) {
                return false;
            }
            i++;
        }

        if(counter == 0 || (counter == 1 && nums[0] >= nums[n-1]))
            return true;
        return false;
    }
};

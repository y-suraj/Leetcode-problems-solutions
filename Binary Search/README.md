# Binary Search

## [704. Binary Search](https://leetcode.com/problems/binary-search/description/)
```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while(low <= high) {
            int mid = (low + high) / 2;
            if(nums[mid] == target)
                return mid;
            else if(target > nums[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};
TC: O(log(N)), where N is the number of elements in the array/vector
```

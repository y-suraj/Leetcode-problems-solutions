# Arrays

## Easy
### [283. Move Zeroes](https://leetcode.com/problems/move-zeroes/description/)
Brute force approach:
```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int countZeros = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                nums.erase(nums.begin() + i);
                countZeros++;
                i--;
            }
        }
        while(countZeros > 0) {
            nums.push_back(0);
            countZeros--;
        }
    }
};
// TC: O(N^2), where N is the number of integers in the array.
// N^2 because `erase()` takes N time. Edge case: nums = [0, 0, 0, 0, 0]
```

Optimal approach:
```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = -1;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                j = i;
                break;
            }
        }

        if(j == -1) return;

        for(int i = j + 1; i < n; i++) {
            if(nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};
// TC: O(N), where N is the number of integers in the array.
```
Reference: [Move all Zeros to the end of the array](https://takeuforward.org/data-structure/move-all-zeros-to-the-end-of-the-array/), [Video](https://youtu.be/wvcQg43_V8U?t=1633)

## Refernces

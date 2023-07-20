# Arrays

## Easy

### [1. Two Sum](https://leetcode.com/problems/two-sum/description/)
Approach 1 - Brute:
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> id(2, 0); 
        int x = target;
        int arrSize = nums.size();

        for(int i=0; i<arrSize-1; i++)
        {
            x-=nums[i];
            id[0] = i;

            for(int j=i+1; j<arrSize; j++)
                if(nums[j]==x)
                {
                    id[1] = j;
                    i = arrSize;
                    break;
                }
                
                x = target;
        }
        return id;
    }
};
// TC: O(N^2), where N is the number of elements in the array
```

Approach 2 - Better
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Create a map to store the elements and their indices
        map<int, int> mpp;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            // Consider the current element as part 1 of the pair
            int part1 = nums[i]; 
            // Calculate the required second part of the pair
            int part2 = target - part1;
            if(mpp.find(part2) != mpp.end()) {
                // If the second part is found in the map, 
                // it means we have found the pair
                // Return the indices of the two elements that sum up to the target
                return {mpp[part2], i};
            }
            // If the second part is not found, 
            // store the current element in the map
            // with its index as the value, 
            // so we can use it for future calculations
            mpp[part1] = i;
        }
        return {-1, -1};
    }
};
// TC: O(N * logN), where N is the number of elements in the array
```
Reference: TUF - [Video](https://www.youtube.com/watch?v=UXDSeD9mN-k)

### [2Sum - Alt](https://www.codingninjas.com/studio/problems/reading_6845742) - coding ninja
Optimal solution
```cpp
string read(int n, vector<int> book, int target)
{
    // Using the two pointer approach
    int left = 0, right = n - 1;
    sort(book.begin(), book.end());

    while(left < right) {
        int sum = book[left] + book[right];
        if(sum == target) {
            return "YES";
        }
        else if(sum < target) {
            left++;
        }
        else {
            right--;
        }
    }
    return "NO";
}
TC: O(N), where N is the number of elements in the array.
```
Reference: TUF - [Video](https://www.youtube.com/watch?v=UXDSeD9mN-k)

### [189. Rotate Array](https://leetcode.com/problems/rotate-array/description/)
Approach 1:
```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k > n) k = k % n;
        int start = n - k;
        vector<int> answer;

        for(int i = start; i < n; i++){
            answer.push_back(nums[i]);
        }
        for(int i = 0; i < start; i++){
            answer.push_back(nums[i]);
        }
        for(int i = 0; i < n; i++)
            nums[i] = answer[i];
    }
};
// TC: O(N)
// SC: O(N)
// Here N is the number of integers in the array/vector
```
Reference: [Rotate array by K places](https://youtu.be/wvcQg43_V8U)

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

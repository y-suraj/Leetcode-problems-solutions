class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sort the input array
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        int n = nums.size();

        // loop through all elements of the array
        for (int i = 0; i < n; i++) {
            // skip the element if it is the same as the previous one
            // to avoid duplicates
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // set two pointers, left and right
            int l = i + 1, r = n - 1;
            while (l < r) {
                // calculate the sum of the three elements
                int sum = nums[i] + nums[l] + nums[r];
              
                // if the sum is 0, add the three elements to the result list
                if (sum == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    // move the left pointer to the right and skip duplicates
                  
                    while (l < r && nums[l] == nums[l + 1]) l++;
                    // move the right pointer to the left and skip duplicates
                    while (l < r && nums[r] == nums[r - 1]) r--;
                    l++;
                    r--;
                } else if (sum < 0) {
                    // move the left pointer to the right if the sum is less than 0
                    l++;
                } else {
                    // move the right pointer to the left if the sum is greater than 0
                    r--;
                }
            }
        }
        return res;
    }
};

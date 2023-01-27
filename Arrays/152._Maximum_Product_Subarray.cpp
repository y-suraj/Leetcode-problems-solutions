class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int maxProd = 1 , minProd = 1, res = INT_MIN;

        for(int i = 0; i < n; i++){
            int temp = maxProd;

            // storing maxProd in temp as it's value will change in next line 
            maxProd = max({nums[i], maxProd*nums[i], minProd*nums[i]});
            minProd = min({nums[i], temp*nums[i], minProd*nums[i]});

            res = max({maxProd,minProd,res});
        }
        return res;
    }
};

// useful testcase
// [2,-5,-2,-4,3]
/* mx=1, mn=1

i = 0, temp = 1, nums = 2
mx = 2, 2, 2 = 2
mn = 2, 2, 2 = 2

i = 1, temp = 2, nums = -5
mx = -5, -10, -10 = -5
mn = -5, -10, -10 = -10

i = 2, temp = -5, nums = -2
mx = -2, 10, 20 = 20
mn = -2, 10, 20 = -2

i = 3, temp = 20, nums = -4
mx = -4, -80, 8 = 8
mn = -4, -80, 8 = -80

i = 4, temp = 8, nums = 3
mx = 3, 24, -240 = 24
mn = 3, 24, -240 = -240
ans = 24
*/

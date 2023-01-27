class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int maxProd =1 , minProd=1, res = INT_MIN;

        for(int i =0;i<n;i++){
            int temp = maxProd;

            // storing maxProd in temp as it's value will change in next line 
            maxProd = max({nums[i], maxProd*nums[i], minProd*nums[i]});
            minProd = min({nums[i], temp*nums[i], minProd*nums[i]});

            res = max({maxProd,minProd,res});
        }
        return res;
    }
};

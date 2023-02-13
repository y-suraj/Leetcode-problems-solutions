class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;

        for(int &x : nums)
            res^=x;

        int n = nums.size();
        for(int i=0; i<=n; i++)
            res^=i;

        return res;
    }
};

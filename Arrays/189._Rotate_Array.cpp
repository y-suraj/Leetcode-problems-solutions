class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k>n) k = k%n;
        int start = abs(n-k);
        vector<int> answer;

        for(int i = start; i<n; i++){
            answer.push_back(nums[i]);
        }
        for(int i = 0; i<start; i++){
            answer.push_back(nums[i]);
        }
        for(int i=0; i<n; i++)
            nums[i] = answer[i];
    }
};

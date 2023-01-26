class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
    int temp = 1;
    vector<int> answer;
    int numsSize = nums.size();

    for(int i=0; i<numsSize; i++)
    {
        answer.push_back(temp);
        temp *= nums[i];
    }
    temp = 1;
    for(int i= numsSize-1; i>=0; i--)
    {
        answer[i] *= temp;
        temp *= nums[i];
    }
    return answer;
    }
};

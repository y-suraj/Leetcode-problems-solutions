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

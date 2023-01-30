class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int mid = high/2;

        if(high==0)
            return nums[0];

        if(nums[low]<nums[low+1] && nums[low]<nums[high])
                return nums[low];

        while(low<high){
            mid = (low+high)/2;

            if(nums[mid] > nums[mid+1])
                return nums[mid+1];

            if(nums[mid-1] > nums[mid])
                return nums[mid];
                
            if(nums[low] > nums[low+1])
                return nums[low+1];

            if(nums[high-1] > nums[high])
                return nums[high];
                
            if(nums[low] < nums[mid])
                low = mid+1;
            else
                high = mid-1;
        }
        return -1;
    }
};

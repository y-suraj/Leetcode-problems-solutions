class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int maxAr = 0;
        int left = 0, right = height.size() - 1;

        while(left < right){
            int minHeight = min(height[left], height[right]);
            maxAr = max(maxAr, minHeight * (right - left));

            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        return maxAr;
    }
};

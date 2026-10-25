class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool isIncreasing = true;
        bool isDecreasing = true;
        
        for (int i = 1; i < nums.size(); i++) {
            // If the current element is greater than the previous, it can't be decreasing
            if (nums[i] > nums[i - 1]) {
                isDecreasing = false;
            }
            // If the current element is less than the previous, it can't be increasing
            if (nums[i] < nums[i - 1]) {
                isIncreasing = false;
            }
        }
        
        // It is monotonic if it remained either purely increasing or purely decreasing
        return isIncreasing || isDecreasing;
    }
};
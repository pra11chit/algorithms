class Solution {
public:
    void sortColors(vector<int>& nums) {
        //bubble sort
        for (int i = nums.size() - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
    }
};
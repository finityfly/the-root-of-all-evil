class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMin = nums[0], curMax = nums[0];
        int bestMin = nums[0], bestMax = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int tmpMin = curMin, tmpMax = curMax;
            curMin = min(nums[i], min(nums[i] * tmpMin, nums[i] * tmpMax));
            curMax = max(nums[i], max(nums[i] * tmpMin, nums[i] * tmpMax));
            bestMin = min(bestMin, curMin);
            bestMax = max(bestMax, curMax);
        }
        return bestMax;
    }
};
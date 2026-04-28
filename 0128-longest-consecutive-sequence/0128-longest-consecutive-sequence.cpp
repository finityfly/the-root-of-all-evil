class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        set<int> s(nums.begin(), nums.end());
        int prev = INT_MAX, cur=1, ans=1;
        for (auto i : s) {
            if (prev == INT_MAX) {
                cur = 1;
            } else if (i == prev + 1) {
                cur++;
                ans = max(ans, cur);
            } else {
                cur = 1;
            }
            prev = i;
        }
        return ans;
    }
};
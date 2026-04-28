class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 1;
        for (int num : s) {
            if (s.find(num-1) != s.end()) continue;
            else {
                int i = 1;
                while (s.find(num+i) != s.end()) {
                    ++i;
                }
                longest = max(longest, i);
            }
        }
        return longest;
    }
};
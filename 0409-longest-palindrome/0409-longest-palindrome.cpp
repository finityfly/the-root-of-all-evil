class Solution {
public:
    int longestPalindrome(string s) {
        bool hasOdd = false;
        int cnt[52];
        int cur = 0;
        for (const char& c : s) {
            if (c >= 'a' && c <= 'z') {
                cnt[c-'a']++;
            } else if (c >= 'A' && c <= 'Z') {
                cnt[26+c-'A']++;
            }
        }
        for (int i = 0; i < 52; ++i) {
            if (cnt[i] % 2 == 1) hasOdd = 1;
            cur += cnt[i] - (cnt[i] % 2 == 1);
        }
        return cur + hasOdd;
    }
};
class Solution {
public:
    int dp[101];
    int numWays(const string& s, int ind) {
        if (ind == -1) return 1;
        if (dp[ind]) return dp[ind];
        if (s[ind] == '0') {
            if (ind >= 1 && (s[ind-1] == '1' || s[ind-1] == '2')) dp[ind] += numWays(s, ind-2);
            else if (ind == 0) return 0;
        } else {
            if (ind >= 1 && (s[ind-1] == '1' || (s[ind-1] == '2' && (int)(s[ind]-'0') <= 6))) {
                dp[ind] += numWays(s, ind-2);
            }
            dp[ind] += numWays(s, ind-1);
        }
        return dp[ind];
    }

    int numDecodings(string s) {
        memset(dp, 0, sizeof(dp));
        return numWays(s, s.length()-1);
    }
};
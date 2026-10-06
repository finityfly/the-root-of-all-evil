class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0, res = 0;
        for (char c : s) {
            if (c == '(') {
                cnt++;
            } else {
                if (cnt == 0) {
                    res++;
                } else {
                    cnt--;
                }
            }
        }
        return res + cnt;
    }
};
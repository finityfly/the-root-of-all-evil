// @leet start
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        stack<char> st;
        vector<int> res(seq.length(), 0);
        // get the current parenthesis maximum depth div 2
        int cur = 0, maxD = 0;
        for (char c : seq) {
            if (c == '(') {
                cur++;
                maxD = max(maxD, cur);
            } else {
                cur--;
            }
        }
        // at the d/2, push the char into the stack and create the return VPS encoding
        maxD = maxD / 2;
        cur = 0;
        for (int i = 0; i < seq.length(); ++i) {
            if (seq[i] == ')') cur--;
            if (cur >= maxD) {
                res[i] = 1;
            }
            if (seq[i] == '(') cur++;
        }
        return res;
    }
};
// @leet end

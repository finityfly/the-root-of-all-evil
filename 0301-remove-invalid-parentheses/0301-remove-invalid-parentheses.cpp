class Solution {
public:
    unordered_set<string> res;

    void solve(const string& s, string& curString, int ind, int lb, int rb, int bal) {
        if (ind == s.length()) {
            if (lb == 0 && rb == 0 && bal == 0) {
                res.insert(curString);
            }
            return;
        }
        char c = s[ind];
        if (c == ')') {
            // check if bal is good to not put into curString
            if (rb > 0) {
                solve(s, curString, ind+1, lb, rb-1, bal);
            }
            // take char
            if (bal > 0) {
                curString.push_back(c);
                solve(s, curString, ind+1, lb, rb, bal-1);
                curString.pop_back();
            }

        } else if (c == '(' ) {
            // check if bal is good to not put into curString
            if (lb > 0) {
                solve(s, curString, ind+1, lb-1, rb, bal);
            }
            // take char
            curString.push_back(c);
            solve(s, curString, ind+1, lb, rb, bal+1);
            curString.pop_back();

        } else {
            curString.push_back(c);
            solve(s, curString, ind+1, lb, rb, bal);
            curString.pop_back();
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        // backtracking and breadth first search
        int lb = 0, rb = 0;
        for (char c : s) {
            if (c == '(') lb++;
            else if (c == ')') {
                if (lb) lb--;
                else if (!lb) rb++;
            }
        }
        string curString = "";
        solve(s, curString, 0, lb, rb, 0);
        vector<string> out(res.begin(), res.end());
        return out;
    }
};
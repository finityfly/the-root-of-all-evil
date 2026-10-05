class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        for (char c : s) {
            if (c == '(') {
                st.push(0);
            } else {
                int t = st.top(); st.pop();
                if (t == 0) {
                    int b = st.top(); st.pop();
                    st.push(b + 1);
                } else {
                    int b = st.top(); st.pop();
                    st.push(b + 2 * t);
                }
            }
        }
        return st.top();
    }
};
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> matching = {
            {')', '('},
            {']', '['},
            {'}', '{'},
        };
        for (char c : s) {
            if (matching.find(c) == matching.end()) {
                st.push(c);
            } else {
                if (st.empty() || st.top() != matching[c]) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};

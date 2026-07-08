class Solution {
public:
    string removeKdigits(string num, int k) {

        vector<char> st;

        for (char digit : num) {

            while (!st.empty() &&
                   k > 0 &&
                   st.back() > digit) {

                st.pop_back();
                k--;
            }

            st.push_back(digit);
        }

        // Remove remaining digits from the end
        while (k > 0) {
            st.pop_back();
            k--;
        }

        // Build answer without leading zeros
        string ans;

        bool leadingZero = true;

        for (char ch : st) {

            if (leadingZero && ch == '0')
                continue;

            leadingZero = false;
            ans += ch;
        }

        return ans.empty() ? "0" : ans;
    }
};
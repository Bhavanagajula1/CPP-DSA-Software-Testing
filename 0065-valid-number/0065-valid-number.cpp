class Solution {
public:
    bool isNumber(string s) {
        bool digit = false;
        bool dot = false;
        bool exp = false;
        bool digitAfterExp = true;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            if (isdigit(ch)) {
                digit = true;
                if (exp)
                    digitAfterExp = true;
            }
            else if (ch == '+' || ch == '-') {
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            }
            else if (ch == '.') {
                if (dot || exp)
                    return false;
                dot = true;
            }
            else if (ch == 'e' || ch == 'E') {
                if (exp || !digit)
                    return false;
                exp = true;
                digitAfterExp = false;
            }
            else {
                return false;
            }
        }

        return digit && digitAfterExp;
    }
};
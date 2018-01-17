class Solution {

public:

    int myAtoi(string str) {

        int i = 0;

        bool neg = false;

        int len = str.length();

        int res = 0;

        // skip space

        while (i < len && isspace(str[i])) i++;

        // sign

        if (str[i] == '-') {

            neg = true;

            i++;

        } else if (str[i] == '+') {

            i++;

        }

        for (; i < len && isdigit(str[i]); i++) {

            int d = str[i] - '0';

            if (neg) {

                if (res < (INT_MIN+d)/10) return INT_MIN;

                res = res*10 - d;

            } else {

                if (res > (INT_MAX-d)/10) return INT_MAX;

                res = res*10 + d;

            }

        }

        return res;

    }

};

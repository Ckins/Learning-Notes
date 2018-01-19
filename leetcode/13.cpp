class Solution {

public:

    int getV(char c) {

        int i;

        bool found = false;

        char alph[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

        int nums[] = {1, 5, 10, 50, 100, 500, 1000};

        for (i = 0; i < 7; i++) {

            if (alph[i] == c) {

                found = true;

                break;

            }

        }

        if (found) return nums[i];

        else return -1;

    }



    int romanToInt(string s) {

        int res;

        int i = s.size() - 1;

        if (i >= 0) {

            res = getV(s[i]);

        } else {

            res = 0;

        }

        for (i = s.size() - 2; i >= 0; i--) {

            if (getV(s[i]) >= getV(s[i+1])) {

                res += getV(s[i]);

            } else {

                res -= getV(s[i]);

            }

        }

        return res;

    }

};

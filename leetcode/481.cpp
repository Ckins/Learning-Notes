#include <iostream>
#include <vector>
class Solution;

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
		vector<int> first_phase;
		vector<int> pos_vec;
        int tmp = 0;
		int res = 0;
		int i = 0;
		bool init = true;
        while (i < nums.size()) {
        	if (nums[i] != 0) {
               	tmp += nums[i++];
        	} else {
				first_phase.push_back(tmp);
				if (i != 0) first_phase.push_back(0);
				tmp = 0;
				i++;
				if (i < nums.size() && nums[i] == 0) first_phase.push_back(0);
				while (i < nums.size() && nums[i] == 0) i++;
           	}
		}
		if (tmp != 0) first_phase.push_back(tmp);

		
		for (int j = 0; j < first_phase.size(); j++) {
			// cout << first_phase[j] << " ";
			if (first_phase[j] == 0) {
				pos_vec.push_back(j);
			}
		}

		// cout << first_phase.size() << endl;;

		if (pos_vec.size() == 0) {
			for (auto &c : first_phase) res += c;
		} else if (pos_vec.size() == 1) {
			for (auto &c : first_phase) res += c;
			res += 1;
		} else {
			pos_vec.push_back(first_phase.size());
			int prev = pos_vec[0];
			int temp = 0;
			int max = 0;
			for (int j = 0; j < pos_vec[1]; j++) max += first_phase[j];
			for (int j = 2; j < pos_vec.size(); j++) {
				temp = 0;
				for (int k = prev; k < pos_vec[j]; k++) {
					temp += first_phase[k];
				}
				// cout << "link" << temp << endl;
				prev = pos_vec[j-1];
				max = max > temp ? max : temp;
			}
			res = max + 1;
		}
		return res;
    }
};

int main() {
	Solution s;
	vector<int> n = {1};
	vector<int> n2 = {1,1,1,0,1,1,0,1,1,1,1,1,1,1};
	cout << s.findMaxConsecutiveOnes(n2);
}

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int index = nums.size() - 1;
		bool flag = false; // judge if the permutation is the biggest
		while (index >= 1) {
			if (nums[index] > nums[index - 1]) {
				flag = true;
				int tmp = nums[index - 1];
				int idx = nums.size() - 1;
				while (nums[idx] <= tmp)
					idx--;
				nums[index - 1] = nums[idx];
				nums[idx] = tmp;
				reverse(nums, index);
				break;
			}
			index--;
		}
		if (!flag)
			reverse(nums, 0);
	}

private:
	void reverse(vector<int> &nums, int start) {
		int end = nums.size() - 1;
		int tmp;
		while (start < end) {
			tmp = nums[start];
			nums[start] = nums[end];
			nums[end] = tmp;
			start++;
			end--;
		}
	}
};

int main() {
	Solution s;
	vector<int> nums({ 1,1,5 });
	s.nextPermutation(nums);
	for (int i = 0; i < nums.size(); ++i)
		cout << nums[i] << ' ';
	cout << endl;
	system("pause");
	return 0;
}

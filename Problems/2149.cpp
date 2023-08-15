// 2149. Rearrange Array Elements by Sign
class Solution {
public:
  vector<int> rearrangeArray(const vector<int> &nums) {
    vector<int> res(nums.size());
    int i = -2, j = -1;
    for (int num : nums) (num > 0 ? res[i += 2] : res[j += 2]) = num;

    return res;
  }
};

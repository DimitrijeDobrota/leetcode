class Solution {
  public:
    int longestArithSeqLength(vector<int> &nums) {
        unordered_map<int, vector<int>> um;
        int res = 2;

        for (int i = 0; i < nums.size(); i++)
            um[nums[i]].push_back(i);
        for (const auto &[num1, vec1] : um) {
            res = max(res, (int)vec1.size());
            for (const auto &[num2, vec2] : um) {
                if (num1 == num2) continue;

                auto it = lower_bound(vec2.begin(), vec2.end(), vec1.front() + 1);
                if (it == vec2.end()) continue;

                int diff = num2 - num1, crnt = *it, count = 2, next;
                while (true) {
                    if (!um.count(next = nums[crnt] + diff)) break;
                    auto it = lower_bound(um[next].begin(), um[next].end(), crnt + 1);
                    if (it == um[next].end()) break;
                    crnt = *it, count++;
                }
                res = max(res, count);
            }
        }
        return res;
    }
};

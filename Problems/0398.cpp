#pragma GCC optimize("fast")
static auto _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    return 0;
}();

// O(n) pick, O(1) space
class Solution {
    const vector<int> &nums;

  public:
    Solution(const vector<int> &nums) : nums(nums) {}

    int pick(int target) {
        int n = 0, ans = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != target) continue;
            if (rand() % ++n == 0) ans = i;
        }
        return ans;
    }
};

// O(1) pick, O(n) space
class Solution {
    unordered_map<int, vector<int>> um;

  public:
    Solution(const vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++)
            um[nums[i]].push_back(i);
    }

    int pick(int target) { return um[target][rand() % um[target].size()]; }
};

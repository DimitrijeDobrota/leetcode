#define MOD (int)(1E9 + 7)
#define SIZE (int)(1E5 + 1)
int pows[SIZE] = {1};
static const auto Initialize = [] {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    for (int i = 1; i < SIZE; ++i)
        pows[i] = (pows[i - 1] << 1) % MOD;
    return nullptr;
}();

class Solution {
  public:
    int numSubseq(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), l = 0, r = n - 1;

        int res = 0;
        while (l <= r) {
            if (nums[l] + nums[r] > target)
                r--;
            else
                res = (res + pows[r - l++]) % MOD;
        }
        return res;
    }
};

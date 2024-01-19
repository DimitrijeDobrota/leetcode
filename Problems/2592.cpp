const auto _ = []() {
    ios_base::sync_with_stdio(0);
    cout.tie(NULL);
    cin.tie(NULL);
    return NULL;
}();

// O(nlogn)
class Solution {
  public:
    int maximizeGreatness(vector<int> &nums) const {
        sort(rbegin(nums), rend(nums));

        int res = 0;
        for (int i = 0; i < size(nums); i++) {
            if (nums[i] < nums[res]) res++;
        }

        return res;
    }
};

// O(n)
class Solution {
  public:
    int maximizeGreatness(const vector<int> &nums) const {
        unordered_map<int, int> count;
        int res = 0;
        for (const int n : nums)
            res = max(res, ++count[n]);
        return size(nums) - res;
    }
};

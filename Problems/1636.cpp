class Solution {
  public:
    vector<int> frequencySort(vector<int> &nums) const {
        static int count[201];

        memset(count, 0x00, sizeof(count));
        for (const int n : nums)
            count[n + 100]++;

        sort(begin(nums), end(nums), [&](int a, int b) {
            const int x = count[a + 100];
            const int y = count[b + 100];

            return x != y ? x < y : a > b;
        });

        return nums;
    }
};

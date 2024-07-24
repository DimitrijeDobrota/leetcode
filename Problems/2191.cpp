class Solution {
  public:
    vector<int> sortJumbled(const vector<int> &mapping, vector<int> &nums) const {
        const auto shuffle = [&](int a) {
            if (a == 0) return mapping[0];

            int res = 0, acc = 1;
            while (a > 0) {
                const int digit = a % 10;
                res += acc * mapping[digit];
                acc *= 10;
                a /= 10;
            }

            return res;
        };

        static int idxs[30001], tmp[30001];
        const int n = size(nums);

        for (int i = 0; i < n; i++)
            tmp[i] = shuffle(nums[i]);

        iota(idxs, idxs + n, 0);
        sort(idxs, idxs + n, [&](int a, int b) { return tmp[a] != tmp[b] ? tmp[a] < tmp[b] : a < b; });

        for (int i = 0; i < n; i++)
            tmp[i] = nums[idxs[i]];

        return vector(tmp, tmp + n);
    }
};

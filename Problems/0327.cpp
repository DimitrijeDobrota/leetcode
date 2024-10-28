class SegmentTree {
    const int n;
    vector<long long> t = vector<long long>(2 * n);

  public:
    SegmentTree(int n) : n(n) {}

    int sum(int l, int r) const {
        int res = 0;

        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) res += t[l++];
            if (r & 1) res += t[--r];
        }

        return res;
    }

    void update(int p) {
        for (t[p += n]++; p > 1; p /= 2)
            t[p / 2] = t[p] + t[p ^ 1];
    }
};

class Solution {
  public:
    int countRangeSum(const vector<int> &nums, int lower, int upper) const {
        const int n = size(nums);
        vector<long long> prefix(n + 1);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = 1ll * prefix[i] + nums[i];
        }

        vector<long long> possible;
        for (const long long n : prefix) {
            possible.push_back(n);
            possible.push_back(n - lower);
            possible.push_back(n - upper);
        }

        const int m = size(possible);
        static int idxs[300004];
        iota(idxs, idxs + m, 0);
        sort(idxs, idxs + m, [&](int a, int b) { return possible[a] < possible[b]; });

        static int rev[300004];
        for (int i = m - 2, cnt = rev[idxs[m - 1]] = m - 1; i >= 0; i--) {
            if (possible[idxs[i]] != possible[idxs[i + 1]]) cnt--;
            rev[idxs[i]] = cnt;
        }

        int res = 0;
        SegmentTree seg(size(possible));
        for (int i = 0; i <= n; i++) {
            const int low = rev[i * 3 + 2];
            const int high = rev[i * 3 + 1];
            res += seg.sum(low, high + 1);
            seg.update(rev[i * 3]);
        }

        return res;
    }
};

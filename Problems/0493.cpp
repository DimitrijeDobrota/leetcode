class SegmentTree {
    const int n;
    vector<int> t = vector<int>(2 * n, 1);

  public:
    SegmentTree(const int n) : n(n) {
        for (int i = n - 1; i > 0; i--)
            t[i] = t[i * 2] + t[i * 2 + 1];
    }

    int sum(int l, int r) const {
        int res = 0;

        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) res += t[l++];
            if (r & 1) res += t[--r];
        }

        return res;
    }

    void update(int p) {
        for (t[p += n]--; p > 1; p /= 2)
            t[p / 2] = t[p] + t[p ^ 1];
    }
};

class Solution {
  public:
    int reversePairs(const vector<int> &nums) const {
        const int n = size(nums);

        // sort the array using index array
        static int idxs[50001];
        iota(idxs, idxs + n, 0);
        sort(idxs, idxs + n, [&](int a, int b) { return nums[a] < nums[b]; });

        static int rev[50001];
        for (int i = 0; i < n; i++) {
            rev[idxs[i]] = i;
        }

        int res = 0;
        SegmentTree seg(n);
        for (int i = n - 1; i >= 0; i--) {
            seg.update(rev[i]);
            const auto cmp = [&](long long value, int &idx) { return value < nums[idx]; };
            const auto it = upper_bound(idxs, idxs + n, nums[i] * 2ll, cmp);
            if (it == idxs + n) continue;
            res += seg.sum(it - idxs, n);
        }

        return res;
    }
};

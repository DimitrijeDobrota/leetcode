class SegmentTree {
    const int n;
    vector<int> t = vector<int>(2 * n);

  public:
    SegmentTree(const vector<int> nums) : n(size(nums)) {
        for (int i = 0; i < n; i++)
            t[n + i] = nums[i];
        for (int i = n - 1; i > 0; i--)
            t[i] = t[i * 2] + t[i * 2 + 1];
    }

    int sum(int l, int r) const {
        int res = 0;

        for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) res += t[l++];
            if (r & 1) res += t[--r];
        }

        return res;
    }

    void update(int p, int val) {
        for (t[p += n] = val; p > 1; p /= 2)
            t[p / 2] = t[p] + t[p ^ 1];
    }
};

class NumArray {
    SegmentTree seg;

  public:
    NumArray(const vector<int> &nums) : seg(nums) {}
    void update(int index, int val) { seg.update(index, val); }
    int sumRange(int left, int right) const { return seg.sum(left, right); }
};

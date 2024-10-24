class SegmentTree {
    const int n;
    vector<int> t = vector<int>(2 * n);

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
    vector<int> countSmaller(const vector<int> &nums) const {
        const int n = size(nums);
        SegmentTree seg(20001);

        vector<int> res(n);
        for (int i = n - 1; i >= 0; i--) {
            seg.update(nums[i] + 10000);
            res[i] = seg.sum(0, nums[i] + 10000);
        }

        return res;
    }
};

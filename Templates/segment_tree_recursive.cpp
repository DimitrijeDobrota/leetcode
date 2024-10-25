class SegmentTree {
    const int n;
    vector<int> t = vector<int>(4 * n);

    void build(const vector<int>& nums, int idx, int left, int right) {
        if (left == right) {
            t[idx] = nums[left];
            return;
        }

        const int mid = (left + right) / 2;
        build(nums, idx * 2, left, mid);
        build(nums, idx * 2 + 1, mid + 1, right);
        t[idx] = t[idx * 2] + t[idx * 2 + 1];
    }

    int sum(int idx, int left, int right, int l, int r) const {
        if (l > r) return 0;
        if (l == left && r == right) return t[idx];

        const int mid = (left + right) / 2;
        return sum(idx * 2, left, mid, l, min(r, mid))
             + sum(idx * 2 + 1, mid + 1, right, max(l, mid + 1), r);
    }

    void update(int idx, int left, int right, int pos, int val) {
        if (left == right) {
            t[idx] = val;
            return;
        }

        const int mid = (left + right) / 2;
        if (pos <= mid) update(idx * 2, left, mid, pos, val);
        else update(idx * 2 + 1, mid + 1, right, pos, val);
        t[idx] = t[idx * 2] + t[idx * 2 + 1];
    }

public:
    SegmentTree(const vector<int> nums): n(size(nums)) {
        build(nums, 1, 0, n - 1);
    }

    int sum(int left, int right) const {
        return sum(1, 0, n - 1, left, right);
    }

    void update(int pos, int val) {
        update(1, 0, n - 1, pos, val);
    }
};

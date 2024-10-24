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

        static int idxs[50001];
        iota(idxs, idxs + n, 0);
        sort(idxs, idxs + n, [&](int a, int b) { return nums[a] < nums[b]; });

        vector<int> count;      // count the number of each different value
        map<long long, int> um; // map each number to its position in sorted unique array
        int diff = 0, prev = nums[idxs[0]], cnt = 1;
        for (int i = 1; i < n; i++, cnt++) {
            const int crnt = nums[idxs[i]];
            if (crnt == prev) continue;

            um[prev] = size(count);
            count.push_back(cnt);
            prev = crnt;
            cnt = 0;
        }
        um[prev] = size(count);
        count.push_back(cnt);

        int res = 0;
        SegmentTree seg(count); // tree is indexed by position in sorted array
        for (int i = n - 1; i >= 0; i--) {
            // remove current element, and check for left pair in the rest
            seg.update(um[nums[i]]);
            const auto it = um.upper_bound(nums[i] * 2ll);
            if (it == end(um)) continue;
            res += seg.sum(it->second, size(count));
        }

        return res;
    }
};

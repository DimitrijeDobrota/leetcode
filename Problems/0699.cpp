class SegmentTree {
    const int n;
    vector<int> t = vector<int>(2 * n);

  public:
    SegmentTree(int n) : n(n) {}

    int sum(int l, int r) const {
        int res = 0;

        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) res = max(res, t[l++]);
            if (r & 1) res = max(res, t[--r]);
        }

        return res;
    }

    void update(int p, int val) {
        for (t[p += n] = val; p > 1; p /= 2)
            t[p / 2] = max(t[p], t[p ^ 1]);
    }
};

class Solution {
  public:
    vector<int> fallingSquares(const vector<vector<int>> &positions) const {
        vector<int> possible;
        for (const auto &pos : positions) {
            possible.push_back(pos[0]);
            possible.push_back(pos[0] + pos[1]);
        }

        const int m = size(possible);
        static int idxs[2001];
        iota(idxs, idxs + m, 0);
        sort(idxs, idxs + m, [&](int a, int b) { return possible[a] < possible[b]; });

        static int rev[2001];
        for (int i = m - 2, cnt = rev[idxs[m - 1]] = m - 1; i >= 0; i--) {
            if (possible[idxs[i]] != possible[idxs[i + 1]]) cnt--;
            rev[idxs[i]] = cnt;
        }

        int maxi = 0;
        vector<int> res;
        SegmentTree seg(m);
        for (int i = 0; i < size(positions); i++) {
            const int a = rev[i * 2], b = rev[i * 2 + 1];
            const int crnt = positions[i][1] + seg.sum(a, b);
            res.push_back(maxi = max(maxi, crnt));
            for (int i = a; i < b; i++) {
                seg.update(i, crnt);
            }
        }

        return res;
    }
};

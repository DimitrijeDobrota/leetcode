class DetectSquares {
    using point_t = tuple<int, int>;

    unordered_map<int, unordered_set<int>> ys;
    static int cnt[1001][1001];

  public:
    DetectSquares() { memset(cnt, 0x00, sizeof(cnt)); }

    void add(const vector<int> &point) {
        const int x = point[0];
        const int y = point[1];

        cnt[x][y]++;
        ys[x].insert(y);
    }

    int count(const vector<int> &point) {
        const int x = point[0];
        const int y = point[1];
        int res = 0;

        for (const auto yp : ys[point[0]]) {
            const int len = abs(y - yp);
            if (!len) continue;
            if (x + len <= 1000) res += cnt[x][yp] * cnt[x + len][y] * cnt[x + len][yp];
            if (x >= len) res += cnt[x][yp] * cnt[x - len][y] * cnt[x - len][yp];
        }

        return res;
    }
};

int DetectSquares::cnt[1001][1001];

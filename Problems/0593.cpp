class Solution {
    static int distance(const vector<int> p1, const vector<int> p2) {
        const int x = p1[0] - p2[0];
        const int y = p1[1] - p2[1];

        return x * x + y * y;
    }

  public:
    bool validSquare(const vector<int> &p1, const vector<int> &p2, const vector<int> &p3,
                     const vector<int> &p4) const {
        if (p1 == p2) return false;

        int d[] = {
            distance(p1, p2), distance(p1, p3), distance(p1, p4),
            distance(p2, p3), distance(p2, p4), distance(p3, p4),
        };

        sort(d, d + 6);

        return d[0] == d[1] && d[0] == d[2] && d[0] == d[3] && 2 * d[0] == d[4] && 2 * d[0] == d[5];
    }
};

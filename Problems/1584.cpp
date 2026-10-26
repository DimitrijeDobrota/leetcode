#include "../Templates/Union_Find.cpp"

class Solution {
    typedef array<int, 3> edge;
    typedef vector<int> point;

    int distance(const point &p1, const point &p2) { return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]); }

  public:
    int minCostConnectPoints(vector<vector<int>> &points) {
        auto cmp = [](const edge &a, const edge &b) { return a[2] > b[2]; };
        priority_queue<edge, vector<edge>, decltype(cmp)> pq(cmp);
        UnionFind uf(points.size());

        for (int i = 0; i < points.size(); i++)
            for (int j = i + 1; j < points.size(); j++)
                pq.push({i, j, distance(points[i], points[j])});

        int res = 0;
        while (uf.count() != 1) {
            auto [s, d, w] = pq.top();
            pq.pop();
            if (uf.connected(s, d)) continue;
            uf.join(s, d);
            res += w;
        }
        return res;
    }
};

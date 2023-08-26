class Solution {
    int m, n, src, color;
    vector<vector<int>> *image;
    queue<pair<int, int>> q;

    int valid(int sr, int sc) { return sr >= 0 && sr < m && sc >= 0 && sc < n; }

    void add(int sr, int sc) {
        if (valid(sr, sc) && (*image)[sr][sc] == src) {
            (*image)[sr][sc] = color;
            q.push(make_pair(sr, sc));
        }
    }

  public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color) {
        src = image[sr][sc];
        if (src == color) return image;

        m = image.size();
        n = image[0].size();
        this->color = color;
        this->image = &image;

        q.push(make_pair(sr, sc));
        image[sr][sc] = color;

        while (!q.empty()) {
            int sr = q.front().first;
            int sc = q.front().second;
            q.pop();

            add(sr + 1, sc);
            add(sr - 1, sc);
            add(sr, sc + 1);
            add(sr, sc - 1);
        }

        return image;
    }
};

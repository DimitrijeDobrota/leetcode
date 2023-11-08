class Solution {
  public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) const {
        const int x = abs(fx - sx), y = abs(fy - sy);
        if (!x && !y && t == 1) return false;
        return max(x, y) <= t;
    }
};

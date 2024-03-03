class Solution {
  public:
    int longestString(int x, int y, int z) const {
        if (x == y) return (x + y + z) * 2;
        return (min(x, y) * 2 + z + 1) * 2;
    }
};

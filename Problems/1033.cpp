class Solution {
  public:
    vector<int> numMovesStones(int a, int b, int c) const {
        if (a > b) swap(a, b);
        if (a > c) swap(a, c);
        if (b > c) swap(b, c);

        if (a + 1 == b && b + 1 == c) return {0, 0};
        return {b - a <= 2 || c - b <= 2 ? 1 : 2, c - a - 2};
    }
};

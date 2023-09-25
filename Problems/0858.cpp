class Solution {
  public:
    int mirrorReflection(int p, int q) {
        while (p % 2 == 0 && q % 2 == 0)
            p >>= 1, q >>= 1;
        if (p & 1) return q & 1;
        return 2;
    }
};

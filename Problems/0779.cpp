class Solution {
  public:
    constexpr int kthGrammar(const int n, const int k) const {
        if (n == 1) return 0;
        const int mid = 1 << (n - 2);
        return k > mid ? !kthGrammar(n - 1, k - mid) : kthGrammar(n - 1, k);
    }
};

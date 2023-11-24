class Solution {
  public:
    char findKthBit(int n, int k) const {
        int flip = 0, l = (1 << n) - 1;
        while (k > 1) {
            if (k == l / 2 + 1) return '1' - flip;
            if (k > l / 2) {
                k = l + 1 - k;
                flip = !flip;
            }
            l /= 2;
        }
        return '0' + flip;
    }
};

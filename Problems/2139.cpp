class Solution {
  public:
    int minMoves(int target, int maxDoubles) const {
        int res = 0;

        while (target > 1 && maxDoubles > 0) {
            if (target & 1) res++;
            target >>= 1;
            maxDoubles--;
            res++;
        }

        return res + target - 1;
    }
};

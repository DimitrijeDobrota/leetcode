class Solution {
  public:
    int passThePillow(int n, int time) const {
        time = time % ((n - 1) * 2) + 1;
        return min(time, n * 2 - time);
    }
};

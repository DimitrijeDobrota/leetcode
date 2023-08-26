class Solution {
public:
  int minFlips(const string &target) {
    int res = 0, looking = 1;
    for (const char c : target) {
      if ((c & 1) != looking) continue;
      looking = !looking;
      res++;
    }
    return res;
  }
};

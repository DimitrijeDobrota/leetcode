class Solution {
  public:
    bool canAliceWin(int n) const {
        int current = 10;
        bool result = false;
        while (n >= current) {
            n -= current;
            result = !result;
            current--;
        }
        return result;
    }
};

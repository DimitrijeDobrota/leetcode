class Solution {
  public:
    int minSwaps(const string &s) {
        int size = 0;
        for (const char c : s) {
            if (c == '[')
                size++;
            else if (size > 0)
                size--;
        }
        return (size + 1) / 2;
    }
};

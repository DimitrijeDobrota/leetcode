class Solution {
  public:
    bool winnerOfGame(const string &colors) {
        int a = 0, b = 0, i = 0;
        while (i < colors.size()) {
            int count = 0;
            if (colors[i] == 'A') {
                while (i < colors.size() && colors[i] == 'A')
                    i++, count++;
                if (count > 2) a += count - 2;
            } else {
                while (i < colors.size() && colors[i] == 'B')
                    i++, count++;
                if (count > 2) b += count - 2;
            }
        }
        return a > b;
    }
};

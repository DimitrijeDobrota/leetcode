class Solution {
  public:
    bool isRobotBounded(const string &instructions) const {
        static const int offset_x[] = {0, -1, 0, 1};
        static const int offset_y[] = {1, 0, -1, 0};

        int x = 0, y = 0, dir = 0;
        for (const char instruction : instructions) {
            switch (instruction) {
            case 'G':
                x += offset_x[dir];
                y += offset_y[dir];
                break;
            case 'L': dir = dir == 3 ? 0 : dir + 1; break;
            case 'R': dir = dir == 0 ? 3 : dir - 1; break;
            }
        }

        return (x == 0 && y == 0) || (dir != 0);
    }
};

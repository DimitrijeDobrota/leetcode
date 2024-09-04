class Solution {
  public:
    int robotSim(const vector<int> &commands, vector<vector<int>> &obstacles) const {
        unordered_map<int, unordered_set<int>> us;

        for (const auto &obstacle : obstacles) {
            us[obstacle[0]].emplace(obstacle[1]);
        }

        int res = 0;
        int x = 0, y = 0, dir = 0;
        static const int offset[] = {0, 1, 0, -1, 0};
        for (const auto &command : commands) {
            switch (command) {
            case -2: dir = (dir + 3) % 4; break;
            case -1: dir = (dir + 5) % 4; break;
            default:
                for (int i = 0; i < command; i++) {
                    const int nx = x + offset[dir];
                    const int ny = y + offset[dir + 1];

                    if (us[nx].count(ny)) break;

                    x = nx, y = ny;
                    res = max(res, x * x + y * y);
                }
            }
        }

        return res;
    }
};

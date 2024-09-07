class Solution {
  public:
    int minimumOperations(const vector<int> &nums, int start, int goal) const {
        bool seen[1001] = {0};
        queue<int> q;

        seen[start] = true;
        q.emplace(start);

        for (int lvl = 1; !q.empty(); lvl++) {
            for (int l = size(q); l > 0; l--) {
                const int crnt = q.front();
                q.pop();

                for (const int n : nums) {
                    const int x = crnt ^ n;
                    if (x == goal) return lvl;
                    if (x >= 0 && x <= 1000 && !seen[x]) {
                        seen[x] = true;
                        q.emplace(x);
                    }

                    const int y = crnt + n;
                    if (y == goal) return lvl;
                    if (y >= 0 && y <= 1000 && !seen[y]) {
                        seen[y] = true;
                        q.emplace(y);
                    }

                    const int z = crnt - n;
                    if (z == goal) return lvl;
                    if (z >= 0 && z <= 1000 && !seen[z]) {
                        seen[z] = true;
                        q.emplace(z);
                    }
                }
            }
        }

        return -1;
    }
};

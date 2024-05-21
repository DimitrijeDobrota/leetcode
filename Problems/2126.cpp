class Solution {
  public:
    bool asteroidsDestroyed(int mass, vector<int> &asteroids) const {
        sort(begin(asteroids), end(asteroids));

        for (const int num : asteroids) {
            if (num > mass) return false;
            if (mass > 1e5) break;
            mass += num;
        }

        return true;
    }
};

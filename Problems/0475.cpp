class Solution {
  public:
    int findRadius(vector<int> &houses, vector<int> &heaters) const {
        sort(begin(heaters), end(heaters));
        sort(begin(houses), end(houses));

        int res = 0, crnt;
        const int n = size(houses);
        const int m = size(heaters);
        for (int i = 0, j = 0; i < n; i++) {
            while (j < m && houses[i] >= heaters[j])
                j++;

            int crnt = INT_MAX;

            if (j > 0) crnt = houses[i] - heaters[j - 1];
            if (j != m) crnt = min(crnt, heaters[j] - houses[i]);

            res = max(res, crnt);
        }

        return res;
    }
};

class Solution {
  public:
    int minimumAddedCoins(vector<int> &coins, int target) const {
        int res = 0, get = 0;

        sort(begin(coins), end(coins));
        for (int i = 0; i < size(coins) && get < target; i++) {
            while (get + 1 < coins[i])
                get += get + 1, res++;
            get += coins[i];
        }

        while (get < target)
            get += get + 1, res++;

        return res;
    }
};

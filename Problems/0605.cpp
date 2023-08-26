class Solution {
  public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        int count = 1;
        flowerbed.push_back(0);
        flowerbed.push_back(1);
        for (int crnt : flowerbed) {
            if (!crnt)
                count++;
            else {
                if (count >= 3) n -= (count - 3) / 2 + 1;
                if (n <= 0) return true;
                count = 0;
            }
        }
        return false;
    }
};

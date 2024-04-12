class Solution {
  public:
    int maxBottlesDrunk(int numBottles, int numExchange) const {
        int res = 0;
        while (numBottles >= numExchange) {
            numBottles -= numExchange;
            res += numExchange;
            numBottles++;
            numExchange++;
        }
        return res + numBottles;
    }
};

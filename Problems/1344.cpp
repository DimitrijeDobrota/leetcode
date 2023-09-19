class Solution {
  public:
    double angleClock(int hour, int minutes) {
        double m = (360.0 / 60.0 * minutes);
        double h = (360.0 / 12.0 * hour) + (30.0 / 60.0 * minutes);
        if (h >= 360) h -= 360;
        double res = max(m, h) - min(m, h);
        if (res >= 180) res = 360 - res;
        return res;
    }
};

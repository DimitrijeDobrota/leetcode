class Solution {
    int calc_area(int x1, int y1, int x2, int y2) { return abs(x1 - x2) * abs(y1 - y2); }

  public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area = calc_area(ax1, ay1, ax2, ay2) + calc_area(bx1, by1, bx2, by2);
        int x1, x2, y1, y2;
        x1 = max(ax1, bx1);
        x2 = min(ax2, bx2);
        y1 = max(ay1, by1);
        y2 = min(ay2, by2);
        if (x2 - x1 > 0 && y2 - y1 > 0)
            return area - calc_area(x1, y1, x2, y2);
        else
            return area;
    }
};

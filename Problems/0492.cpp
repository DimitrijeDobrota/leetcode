class Solution {
  public:
    vector<int> constructRectangle(int area) const {
        for (int w = sqrt(area); w > 0; w--) {
            const int l = area / w;
            if (l * w == area) return {l, w};
        }

        return {-1, -1};
    }
};

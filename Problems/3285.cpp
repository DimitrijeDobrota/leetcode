class Solution {
  public:
    vector<int> stableMountains(vector<int> &height, int threshold) {
        vector<int> res;

        for (int i = 1; i < size(height); i++) {
            if (height[i - 1] > threshold) res.push_back(i);
        }

        return res;
    }
};

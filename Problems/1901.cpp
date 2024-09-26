class Solution {
  public:
    vector<int> findPeakGrid(const vector<vector<int>> &mat) const {
        int beg = 0, end = mat[0].size() - 1;

        while (beg <= end) {
            int maxi = 0, mid = beg + (end - beg) / 2;

            for (int i = 0; i < mat.size(); i++) {
                maxi = mat[i][mid] >= mat[maxi][mid] ? i : maxi;
            }

            bool isLeft = mid - 1 >= beg && mat[maxi][mid - 1] > mat[maxi][mid];
            bool isRight = mid + 1 <= end && mat[maxi][mid + 1] > mat[maxi][mid];

            if (!isLeft && !isRight)
                return {maxi, mid};
            else if (isRight)
                beg = mid + 1;
            else
                end = mid - 1;
        }

        return {-1, -1};
    }
};

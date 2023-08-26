class Solution {
  public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat) {
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> um;
        int n = mat.size(), m = mat[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                um[i - j].push(mat[i][j]);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mat[i][j] = um[i - j].top();
                um[i - j].pop();
            }
        }

        return mat;
    }
};

// No extra memory
class Solution {
  public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat) {
        int n = mat.size(), m = mat[0].size();
        for (int k = 0; k < m; k++) {
            for (int i = 0, ik = k; i < n && ik < m; i++, ik++) {
                for (int j = 0, jk = k; j < n && jk < m; j++, jk++) {
                    if (mat[i][ik] < mat[j][jk]) swap(mat[i][ik], mat[j][jk]);
                }
            }
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0, ik = k; i < m && ik < n; i++, ik++) {
                for (int j = 0, jk = k; j < m && jk < n; j++, jk++) {
                    if (mat[ik][i] < mat[jk][j]) swap(mat[ik][i], mat[jk][j]);
                }
            }
        }

        return mat;
    }
};

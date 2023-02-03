class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int n = matrix.size(), m = matrix[0].size(), row = n - 1;
    for (int i = 0; i < n - 1; i++) {
      if (matrix[i + 1][0] > target) {
        row = i;
        break;
      }
    }

    int low = 0, high = m - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (matrix[row][mid] == target)
        return true;
      else if (matrix[row][mid] < target)
        low = mid + 1;
      else
        high = mid - 1;
    }
    return false;
  }
};

// Treat the matrix as a sorted list
class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    int low = 0, high = m * n - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (matrix[mid / m][mid % m] == target) return true;
      if (matrix[mid / m][mid % m] < target)
        low = mid + 1;
      else
        high = mid - 1;
    }
    return false;
  }
};

// Binary Search Tree
class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    int row = 0, col = m - 1;
			
    while (row < n && col > -1) {
        if (matrix[row][col] == target) return true;
        if (target > matrix[row][col]) row++;
        else col--;
    }
    return false;
  }
};


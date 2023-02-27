class Solution {
public:
  Node *construct(vector<vector<int>> &grid, int rowStart, int rowEnd,
                  int colStart, int colEnd) {
    if (rowStart > rowEnd || colStart > colEnd) return nullptr;

    bool isLeaf = true;
    int val = grid[rowStart][colStart];
    for (int i = rowStart; i <= rowEnd; i++) {
      for (int j = colStart; j <= colEnd; j++) {
        if (grid[i][j] != val) {
          isLeaf = false;
          break;
        }
      }
      if (!isLeaf) break;
    }

    if (isLeaf) return new Node(val, true);

    int rowMid = (rowStart + rowEnd) / 2;
    int colMid = (colStart + colEnd) / 2;
    Node *topLeft = construct(grid, rowStart, rowMid, colStart, colMid);
    Node *topRight = construct(grid, rowStart, rowMid, colMid + 1, colEnd);
    Node *bottomLeft = construct(grid, rowMid + 1, rowEnd, colStart, colMid);
    Node *bottomRight = construct(grid, rowMid + 1, rowEnd, colMid + 1, colEnd);
    return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
  }
  Node *construct(vector<vector<int>> &grid) {
    int n = grid.size();
    return construct(grid, 0, n - 1, 0, n - 1);
  }
};

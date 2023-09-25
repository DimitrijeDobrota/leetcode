class Solution {
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        const int n = matrix.size();
        priority_queue<int> heap;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                heap.push(matrix[i][j]);
                if (heap.size() > k) heap.pop();
            }
        }
        return heap.top();
    }
};

class Solution {
    typedef tuple<int, uint8_t, uint8_t> tp;

  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        const int n = matrix.size();
        priority_queue<tp, vector<tp>, greater<tp>> heap;
        for (int i = 0; i < min(n, k); i++)
            heap.push({matrix[i][0], i, 0});

        for (int i = 1; i < k; i++) {
            const auto [elem, row, col] = heap.top();
            heap.pop();
            if (col + 1 < n) heap.push({matrix[row][col + 1], row, col + 1});
        }
        return get<0>(heap.top());
    }
};

class Solution {
    int count(const vector<vector<int>> &matrix, int mid) {
        const int n = matrix.size();
        int i = n - 1, j = 0, count = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] > mid)
                i--;
            else {
                count += i + 1;
                j++;
            }
        }
        return count;
    }

  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        const int n = matrix.size();
        int low = matrix.front().front(), high = matrix.back().back();
        while (low <= high) {
            const int mid = low + (high - low) / 2;
            const int ans = count(matrix, mid);
            if (ans < k)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};

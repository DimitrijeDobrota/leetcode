class Solution {
  private:
    unordered_map<int, int> visited;

  public:
    int integerReplacement(int n) {
        if (n == 1) return 0;
        if (visited.count(n)) return visited[n];

        if (!(n & 1 == 1)) return visited[n] = 1 + integerReplacement(n / 2);
        return visited[n] = 2 + min(integerReplacement(n / 2), integerReplacement(n / 2 + 1));
    }
};

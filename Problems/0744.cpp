class Solution {
public:
  char nextGreatestLetter(vector<char> &letters, char target) {
    if (target >= letters.back()) return letters.front();
    int low = 0, high = letters.size() - 1;
    target++;
    while (low < high) {
      int mid = low + (high - low) / 2;
      if (letters[mid] == target)
        return letters[mid];
      else if (letters[mid] < target)
        low = mid + 1;
      else
        high = mid;
    }
    return letters[high];
  }
};

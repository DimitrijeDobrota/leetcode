class MedianFinder {
  priority_queue<int> left;
  priority_queue<int, vector<int>, greater<int>> right;

public:
  void addNum(int num) {
    if (left.empty() || num < left.top())
      left.push(num);
    else
      right.push(num);

    if (left.size() < right.size()) {
      int temp = right.top();
      right.pop();
      left.push(temp);
    }

    if (left.size() - right.size() > 1) {
      int temp = left.top();
      left.pop();
      right.push(temp);
    }
  }

  double findMedian() {
    if (left.size() > right.size())
      return left.top();
    else
      return (left.top() + right.top()) * 0.5;
  }
};

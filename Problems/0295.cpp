class MedianFinder {
    std::priority_queue<int, std::vector<int>, std::greater<int>> high;
    std::priority_queue<int> low;

    void rebalance() {
        if (std::size(low) > std::size(high) + 1) {
            high.push(low.top());
            low.pop();
        } else if (std::size(high) > std::size(low)) {
            low.push(high.top());
            high.pop();
        }
    }

public:
    MedianFinder() {}
    
    void addNum(int num) {
        if (std::empty(low) || num <= low.top()) {
            low.push(num);
        } else {
            high.push(num);
        }
        rebalance();
    }
    
    double findMedian() const {
        const double lower = low.top();
        return std::size(low) == std::size(high)
            ? (lower + high.top()) / 2.0
            : lower;
    }
};
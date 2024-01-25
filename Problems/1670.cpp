class FrontMiddleBackQueue {
  public:
    deque<int> left, right;

    void balance() {
        if (size(left) > size(right)) {
            right.push_front(left.back());
            left.pop_back();
        }

        if (size(left) + 1 < size(right)) {
            left.push_back(right.front());
            right.pop_front();
        }
    }

    void pushFront(int val) {
        left.push_front(val);
        balance();
    }

    void pushMiddle(int val) {
        left.push_back(val);
        balance();
    }

    void pushBack(int val) {
        right.push_back(val);
        balance();
    }

    int popFront() {
        if (size(left) == 0) {
            if (size(right) == 0) return -1;
            const int res = right.front();
            right.pop_front();
            return res;
        }
        const int res = left.front();
        left.pop_front();
        balance();
        return res;
    }

    int popMiddle() {
        if (size(right) + size(left) == 0) return -1;
        if (size(left) < size(right)) {
            const int res = right.front();
            right.pop_front();
            return res;
        } else {
            const int res = left.back();
            left.pop_back();
            balance();
            return res;
        }
    }

    int popBack() {
        if (size(right) == 0) {
            if (size(left) == 0) return -1;
            const int res = left.back();
            left.pop_back();
            return res;
        }
        const int res = right.back();
        right.pop_back();
        balance();
        return res;
    }
};

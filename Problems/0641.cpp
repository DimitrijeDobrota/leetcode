class MyCircularDeque {
    const int n;
    vector<int> q;

    int size = 0;
    int head = 0, tail = 0;

  public:
    MyCircularDeque(int k) : n(k), q(k) {}

    bool insertFront(int value) {
        if (size == n) return false;
        q[head] = value;
        head = (head + 1) % n;
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (size == n) return false;
        tail = (tail - 1 + n) % n;
        q[tail] = value;
        size++;
        return true;
    }

    bool deleteFront() {
        if (!size) return false;
        head = (head - 1 + n) % n;
        size--;
        return true;
    }

    bool deleteLast() {
        if (!size) return false;
        tail = (tail + 1) % n;
        size--;
        return true;
    }

    int getFront() const { return size ? q[(head - 1 + n) % n] : -1; }
    int getRear() const { return size ? q[tail] : -1; }
    bool isEmpty() const { return size == 0; }
    bool isFull() const { return size == n; }
};

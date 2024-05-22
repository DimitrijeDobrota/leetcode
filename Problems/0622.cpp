class MyCircularQueue {
  public:
    MyCircularQueue(int k) : n(k), q(k) {}

    bool enQueue(int value) {
        if (isFull()) return false;

        q[back++] = value;
        if (back >= n) back -= n;
        size++;

        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;

        if (++front >= n) front -= n;
        size--;

        return true;
    }

    int Front() const {
        if (isEmpty()) return -1;
        return q[front];
    }

    int Rear() const {
        if (isEmpty()) return -1;
        if (back == 0) return q.back();
        return q[back - 1];
    }

    bool isEmpty() const { return size == 0; }

    bool isFull() const { return size == n; }

    const int n;
    vector<int> q;

    int front = 0, back = 0;
    int size = 0;
};

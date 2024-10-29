class SegmentTree {
    struct Node {
        Node *left = nullptr;
        Node *right = nullptr;
        int low;
        int high;
        int value;

        Node(int low, int high, int value) : low(low), high(high), value(value) {}
    } root;

    void update(Node *root, int l, int r, int val) {
        if (root->low == l && root->high == r) {
            root->value = val;
            root->left = root->right = NULL; // memory leak;
            return;
        }

        const int mid = root->low + (root->high - root->low) / 2;

        if (!root->left) {
            root->left = new Node(root->low, mid, root->value);
            root->right = new Node(mid + 1, root->high, root->value);
        }

        if (r <= mid)
            update(root->left, l, r, val);
        else if (l > mid)
            update(root->right, l, r, val);
        else
            update(root->left, l, mid, val), update(root->right, mid + 1, r, val);
        root->value = root->left->value && root->right->value;
    }

    bool query(const Node *root, int l, int r) const {
        if (!root->left) return root->value;
        if (root->low == l && root->high == r) return root->value;

        const int mid = root->low + (root->high - root->low) / 2;

        if (r <= mid)
            return query(root->left, l, r);
        else if (l > mid)
            return query(root->right, l, r);
        return query(root->left, l, mid) && query(root->right, mid + 1, r);
    }

  public:
    SegmentTree(int l, int r, int val) : root(l, r, val) {}

    void update(int l, int r, int val) { return update(&root, l, r, val); }
    bool query(int l, int r) const { return query(&root, l, r); }
};

class RangeModule {
    SegmentTree seg;

  public:
    RangeModule() : seg(0, 1e9, 0) {}

    void addRange(int left, int right) { seg.update(left, right - 1, 1); }

    bool queryRange(int left, int right) { return seg.query(left, right - 1); }

    void removeRange(int left, int right) { seg.update(left, right - 1, 0); }
};

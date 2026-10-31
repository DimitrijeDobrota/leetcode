class TreeAncestor {
    int levels;
    std::vector<std::vector<int>> jump;

  public:
    TreeAncestor(int n, vector<int> &parent)
        : levels(std::bit_width(static_cast<unsigned int>(n))),
          jump(levels, std::vector<int>(n, -1)) {
        jump[0] = parent;
        for (auto level : std::views::iota(1, levels)) {
            for (auto node : std::views::iota(0, n)) {
                const auto halfway = jump[level - 1][node];
                if (halfway == -1) continue;
                jump[level][node] = jump[level - 1][halfway];
            }
        }
    }

    int getKthAncestor(int node, int k) {
        while (node != -1 && k > 0) {
            const auto level = std::countr_zero(static_cast<unsigned int>(k));
            if (level >= levels) return -1;
            node = jump[level][node];
            k &= k - 1;
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */

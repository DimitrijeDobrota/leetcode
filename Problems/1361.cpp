#include "../Templates/Union_Find.cpp"

class Solution {
    bool process(UnionFind &uf, vector<int> &parent, int start, int end) {
        if (end == -1) return true;
        if (parent[end] != -1) return false;
        if (uf.find(start) == uf.find(end)) return false;
        uf.join(start, end);
        parent[end] = start;
        return true;
    }

  public:
    bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild) {
        UnionFind uf(n);
        vector<int> parent(n, -1);

        for (int i = 0; i < n; i++)
            if (!process(uf, parent, i, leftChild[i]) || !process(uf, parent, i, rightChild[i])) return false;

        return uf.count() == 1;
    }
};

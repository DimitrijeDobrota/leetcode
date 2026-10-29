class Solution {
    using Mask = std::uint32_t;

    static Mask characterBit(char character) { return Mask{1} << (character - 'a'); }

    class FenwickXor {
        int size;
        std::vector<Mask> blocks;

        // A positive index ends a block whose length is its lowest set bit.
        static int blockSize(int index) { return 1 << std::countr_zero(static_cast<unsigned int>(index)); }

        void xorAt(int position, Mask value) {
            for (int index = position + 1; index <= size; index += blockSize(index)) {
                blocks[index] ^= value;
            }
        }

        Mask prefixXor(int position) const {
            Mask result = 0;
            for (int index = position + 1; index > 0; index -= blockSize(index)) {
                result ^= blocks[index];
            }
            return result;
        }

      public:
        explicit FenwickXor(int size)
            : size(size),
              blocks(size + 1, 0) {}

        // The stored array is a difference array; right is excluded.
        void rangeXor(int left, int right, Mask value) {
            xorAt(left, value);
            xorAt(right, value);
        }

        Mask changeAt(int position) const { return prefixXor(position); }
    };

  public:
    std::vector<bool> palindromePath(int n, const std::vector<std::vector<int>> &edges, std::string s,
                                     const std::vector<std::string> &queries) const {
        std::vector<std::vector<int>> graph(n);
        for (const auto &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        const int levels = std::bit_width(static_cast<unsigned int>(n));
        std::vector<std::vector<int>> ancestorJump(levels, std::vector<int>(n));
        std::vector<int> subtreeBegin(n), subtreeEnd(n);
        std::vector<Mask> initialPrefix(n);

        struct Event {
            int node;
            int parent;
            bool exiting;
        };

        std::vector<Event> stack{{0, 0, false}};
        int timer = 0;

        while (!stack.empty()) {
            const auto [node, parent, existing] = stack.back();
            stack.pop_back();

            if (existing) {
                subtreeEnd[node] = timer;
                continue;
            }

            subtreeBegin[node] = timer++;
            ancestorJump[0][node] = parent;
            for (int level = 1; level < levels; ++level) {
                ancestorJump[level][node] = ancestorJump[level - 1][ancestorJump[level - 1][node]];
            }

            initialPrefix[node] = characterBit(s[node]);
            if (node != parent) {
                initialPrefix[node] ^= initialPrefix[parent];
            }

            // Descendants are processed before their parent's exit event.
            stack.push_back({node, parent, true});
            for (auto it = graph[node].rbegin(); it != graph[node].rend(); ++it) {
                if (*it != parent) {
                    stack.push_back({*it, node, false});
                }
            }
        }

        const auto isAncestor = [&](int ancestor, int node) {
            return subtreeBegin[ancestor] <= subtreeBegin[node] && subtreeBegin[node] < subtreeEnd[ancestor];
        };

        const auto lowestCommonAncestor = [&](int u, int v) {
            if (isAncestor(u, v)) {
                return u;
            }
            if (isAncestor(v, u)) {
                return v;
            }
            for (int level = levels - 1; level >= 0; --level) {
                if (!isAncestor(ancestorJump[level][u], v)) {
                    u = ancestorJump[level][u];
                }
            }
            return ancestorJump[0][u];
        };

        FenwickXor changes(n);
        const auto currentPrefix = [&](int node) {
            return initialPrefix[node] ^ changes.changeAt(subtreeBegin[node]);
        };

        std::vector<bool> answer;
        answer.reserve(queries.size());

        for (const auto &query : queries) {
            std::istringstream input(query);
            std::string operation;
            input >> operation;

            if (operation == "update") {
                int node;
                char next;
                input >> node >> next;

                const Mask delta = characterBit(s[node]) ^ characterBit(next);
                changes.rangeXor(subtreeBegin[node], subtreeEnd[node], delta);
                s[node] = next;
            } else {
                int u, v;
                input >> u >> v;

                const int ancestor = lowestCommonAncestor(u, v);
                const Mask mask = currentPrefix(u) ^ currentPrefix(v) ^ characterBit(s[ancestor]);
                answer.push_back(std::popcount(mask) <= 1);
            }
        }

        return answer;
    }
};

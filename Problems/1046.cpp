class Solution {
public:
    int lastStoneWeight(const vector<int>& stones) const {
        std::priority_queue<int> pq(std::begin(stones), std::end(stones)); 

        while (std::size(pq) > 1) {
            const auto first = pq.top();
            pq.pop();

            const auto second = pq.top();
            pq.pop();

            if (first != second) {
                pq.emplace(first - second);
            }
        }

        return !std::empty(pq) ? pq.top() : 0;
    }
};

class Solution {
public:
    int lastStoneWeight(vector<int> stones) const {
        std::make_heap(std::begin(stones), std::end(stones));

        while (std::size(stones) > 1) {
            std::pop_heap(std::begin(stones), std::end(stones));
            const auto first = stones.back();
            stones.pop_back();

            std::pop_heap(std::begin(stones), std::end(stones));
            const auto second = stones.back();
            stones.pop_back();

            if (first != second) {
                stones.emplace_back(first - second);
                std::push_heap(std::begin(stones), std::end(stones));
            }
        }

        return !std::empty(stones) ? stones.back() : 0;
    }
};
class Solution {
public:
    int totalFruit(const vector<int>& fruits) const {
        struct Fruit {
            int type = 0;
            int count = 0;
        };
        Fruit type1;
        Fruit type2;

        std::size_t result = 0; 
        std::size_t left = 0; 
        for (const auto right: std::views::iota(0UZ, std::size(fruits))) {
            if (type1.count == 0) type1 = {fruits[right], 1};
            else if (type1.type == fruits[right]) type1.count++;
            else if (type2.count == 0) type2 = {fruits[right], 1};
            else if (type2.type == fruits[right]) type2.count++;
            else {
                while (left <= right) {
                    auto& type = fruits[left] == type1.type ? type1 : type2;
                    left++;
                    if (--type.count == 0) {
                        type = {fruits[right], 1};
                        break;
                    }
                }
            }
            result = std::max(result, right - left + 1);
        }
        return result;
    }
};

class Solution {
public:
    int totalFruit(const vector<int>& fruits) const {
        struct Fruit {
            int type = 0;
            int count = 0;
            int end = 0;
        };
        Fruit type1;
        Fruit type2;

        int result = 0; 
        for (const auto right: std::views::iota(0UZ, std::size(fruits))) {
            if (type1.count == 0) type1 = {fruits[right], 1, 1};
            else if (type1.type == fruits[right]) type1.count++, type1.end++, type2.end = 0;
            else if (type2.count == 0) type2 = {fruits[right], 1, 1}, type1.end = 0;
            else if (type2.type == fruits[right]) type2.count++, type2.end++, type1.end = 0;
            else {
                auto [remove, keep] = fruits[right - 1] == type2.type
                                    ? std::tie(type1, type2)
                                    : std::tie(type2, type1);
                keep.count = keep.end;
                keep.end = 0;
                remove = {fruits[right], 1, 1};
            }
            result = std::max(result, type1.count + type2.count);
        }
        return result;
    }
};

// Original idea
class Solution {
  public:
    vector<vector<string>> suggestedProducts(vector<string> &products, const string &searchWord) {
        sort(begin(products), end(products));

        vector<vector<string>> res(searchWord.size());
        for (int i = 0; i < searchWord.size(); i++) {
            const string search = searchWord.substr(0, i + 1);
            vector<string> found;
            for (const auto &product : products) {
                if (product.size() > i && product[i] == searchWord[i])
                    found.push_back(product);
                else if (found.size())
                    break;
            }
            for (int k = 0; k < min(3ul, found.size()); k++)
                res[i].push_back(found[k]);
            products = found;
        }

        return res;
    }
};

// Optimized range based solution
class Solution {
  public:
    vector<vector<string>> suggestedProducts(vector<string> &products, const string searchWord) {
        sort(begin(products), end(products));
        vector<vector<string>> res(searchWord.size());
        int start = 0, end = products.size();
        for (int i = 0; i < searchWord.size(); i++) {
            const string search = searchWord.substr(0, i + 1);
            bool found = false;
            for (int j = start; j < end; j++) {
                if (products[j].size() > i && products[j][i] == searchWord[i]) {
                    if (!found) start = j;
                    found = true;
                } else if (found) {
                    end = j;
                    break;
                }
            }
            if (!found || start >= end) break;
            for (int j = 0; j < min(3, end - start); j++)
                res[i].push_back(products[start + j]);
        }

        return res;
    }
};

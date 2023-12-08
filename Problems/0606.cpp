class Solution {
  public:
    string tree2str(const TreeNode *root) {
        stack<const TreeNode *> stack;
        stack.push(root);
        string res = "";

        while (!stack.empty()) {
            const TreeNode *temp = stack.top();
            stack.pop();
            if (temp == nullptr)
                res += ')';
            else {
                res += '(' + to_string(temp->val);
                stack.push(nullptr);

                if (temp->right) stack.push(temp->right);

                if (temp->left)
                    stack.push(temp->left);
                else if (temp->right)
                    res += "()";
            }
        }
        return res.substr(1, res.size() - 2);
    }
};

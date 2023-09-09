/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
  public:
    int getImportance(const vector<Employee *> employees, int id) const {
        static const Employee *um[2001];

        memset(um, 0x00, sizeof(um));
        for (const Employee *employee : employees)
            um[employee->id] = employee;

        int res = 0;
        queue<int> q({id});
        while (!q.empty()) {
            int id = q.front();
            q.pop();
            res += um[id]->importance;
            for (const int sub : um[id]->subordinates)
                q.push(sub);
        }

        return res;
    }
};

SELECT EmployeeID AS "Employee"
FROM Employee AS E1, Employee AS E2
WHERE E1.managerID = E2.id AND E1.salary > E2.salary

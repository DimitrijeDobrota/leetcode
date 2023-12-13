SELECT D.name AS 'Department', 
       E.name AS 'Employee', 
       E.salary AS 'Salary' 
FROM Employee E
JOIN Department D
ON E.departmentId = D.id 
WHERE 3 > (
    SELECT COUNT(DISTINCT salary)
    FROM Employee
    WHERE salary > E.salary AND E.departmentId = departmentId
);

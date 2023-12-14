SELECT D.name AS Department,
       E.name AS Employee,
       E.salary
FROM Employee E
LEFT JOIN Department D
ON E.departmentId = D.id
WHERE (D.id, E.salary) IN (
    SELECT departmentId, MAX(salary) AS salary
    FROM Employee
    GROUP BY departmentId
)

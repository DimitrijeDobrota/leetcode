SELECT E.employee_id
FROM Employees E
LEFT JOIN Employees M
ON E.manager_id = M.employee_id
WHERE E.salary < 30000 AND 
      M.employee_id IS NULL AND 
      E.manager_id  IS NOT NULL
ORDER BY E.employee_id

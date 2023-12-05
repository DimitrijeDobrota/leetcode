SELECT M.employee_id,
       M.name,
       COUNT(E.employee_id) AS reports_count,
       ROUND(AVG(E.age), 0) AS average_age
FROM Employees M
LEFT JOIN Employees E
ON M.employee_id = E.reports_to
GROUP BY M.employee_id
HAVING COUNT(E.employee_id) > 0
ORDER BY M.employee_id

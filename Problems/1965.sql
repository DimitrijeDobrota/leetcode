SELECT employee_id
FROM (
    SELECT * FROM Employees LEFT JOIN Salaries USING(employee_id)
    UNION
    SELECT * FROM Employees RIGHT JOIN Salaries USING(employee_id)
) AS T
WHERE salary IS NULL OR
      name IS NULL
ORDER BY employee_id

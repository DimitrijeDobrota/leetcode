SELECT employee_id, IF(employee_id % 2 = 1 AND UPPER(SUBSTR(name, 1, 1)) != 'M', salary, 0) AS bonus
FROM Employees
ORDER BY employee_id

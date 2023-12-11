SELECT name
FROM Employee E
WHERE id IN (
    SELECT managerId
    FROM Employee
    GROUP BY managerId 
    HAVING COUNT(managerId) >= 5
)

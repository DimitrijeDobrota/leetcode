SELECT "Low Salary" AS category,
       SUM(income < 20000) AS accounts_count
FROM Accounts
UNION
SELECT "Average Salary",
       SUM(income >= 20000 AND income <= 50000)
FROM Accounts
UNION
SELECT "High Salary",
       SUM(income > 50000)
FROM Accounts

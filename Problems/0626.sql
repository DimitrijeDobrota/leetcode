SELECT F.id, IFNULL(S.student, F.student) AS student
FROM Seat F
LEFT JOIN Seat S
ON F.id % 2 = 1 AND F.id + 1 = S.id
OR F.id % 2 = 0 AND F.id - 1 = S.id

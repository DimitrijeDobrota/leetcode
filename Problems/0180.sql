SELECT DISTINCT L1.num AS ConsecutiveNums
FROM Logs L1
LEFT JOIN Logs L2 ON L1.id + 1 = L2.id
LEFT JOIN Logs L3 ON L1.id + 2 = L3.id
WHERE L1.num = L2.num AND L2.num = L3.num

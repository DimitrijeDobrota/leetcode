SELECT name, SUM(amount) as balance
FROM Users U
LEFT JOIN Transactions T
ON U.account = T.account
GROUP BY U.account
HAVING SUM(amount) > 10000

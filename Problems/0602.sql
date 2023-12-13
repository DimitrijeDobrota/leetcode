SELECT id, COUNT(*) AS num
FROM (
    SELECT requester_id AS ID
    FROM RequestAccepted
    UNION ALL
    SELECT accepter_id
    FROM RequestAccepted
) AS D
GROUP BY id
ORDER BY COUNT(*) DESC
LIMIT 1


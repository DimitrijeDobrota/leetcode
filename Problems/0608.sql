SELECT id, (
    CASE
        WHEN T.p_id IS NULL THEN 'Root'
        WHEN P.p_id IS NOT NULL THEN 'Inner'
        ELSE 'Leaf'
    END
    ) AS type
FROM TREE T
LEFT JOIN (
    SELECT p_id, COUNT(*) AS count
    FROM Tree
    GROUP BY p_id
) AS P
ON T.id = P.p_id

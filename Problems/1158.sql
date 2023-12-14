SELECT U.user_id AS buyer_id,
       U.join_date,
       COUNT(O.buyer_id) AS orders_in_2019
FROM Users U
LEFT JOIN (
    SELECT buyer_id
    FROM Orders
    WHERE YEAR(order_date) = 2019
) AS O
ON U.user_id = O.buyer_id
GROUP BY U.user_id


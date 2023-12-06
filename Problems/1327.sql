SELECT product_name, SUM(unit) AS unit
FROM Products P
LEFT JOIN Orders O
ON P.product_id = O.product_id AND
   YEAR(order_date) = '2020' AND
   MONTH(order_date) = '02'
GROUP BY product_name
HAVING SUM(unit) >= 100

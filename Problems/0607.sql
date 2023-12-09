SELECT P.name
FROM Orders O
JOIN Company C
ON O.com_id = C.com_id AND C.name = 'RED'
RIGHT JOIN SalesPerson P
ON P.sales_id = O.sales_id
WHERE O.sales_id IS NULL


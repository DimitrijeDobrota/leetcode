SELECT C.Name as Customers
FROM Customers C
LEFT JOIN Orders O
ON C.Id = O.CustomerId
WHERE O.CustomerId is NULL

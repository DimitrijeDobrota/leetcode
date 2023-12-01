SELECT lastName, city, state
FROM Address
RIGHT JOIN Person 
ON Person.personId = Address.personId

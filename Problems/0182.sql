SELECT P1.email AS "Email"
FROM Person AS P1, Person AS P2
WHERE P1.id > P2.id AND P1.email = P2.email

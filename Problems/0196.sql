DELETE P1
FROM Person P1, Person P2
WHERE P1.email = p2.email AND
      p1.id > p2.id

SELECT DISTINCT S1.*
FROM Stadium AS S1, Stadium AS S2, Stadium AS S3
WHERE S1.people >= 100 AND S2.people >= 100 AND S3.people >= 100
    AND ((S1.id + 1 = S2.id AND S1.id + 2 = S3.id)
      OR (S1.id - 1 = S2.id AND S1.id - 2 = S3.id)
      OR (S1.id - 1 = S2.id AND S1.id + 1 = S3.id))
ORDER BY visit_date


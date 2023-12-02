SELECT W2.id
FROM Weather W1, Weather W2
WHERE DATEDIFF(W2.recordDate, W1.recordDate) = 1 AND 
      W1.temperature < W2.temperaturea

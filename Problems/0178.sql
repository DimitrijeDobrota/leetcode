SELECT S.Score, count(DISTINCT t.score) AS 'rank'
FROM Scores S 
JOIN Scores T 
ON S.Score <= T.score
GROUP BY S.Id
ORDER BY S.Score DESC

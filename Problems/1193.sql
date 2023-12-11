SELECT  LEFT(trans_date, 7) AS month, 
        country,
        COUNT(*) AS trans_count, 
        SUM(state = 'approved') AS approved_count,
        SUM(amount) AS trans_total_amount,
        SUM(if(state = 'approved', amount, 0)) AS approved_total_amount
FROM Transactions
GROUP BY YEAR(trans_date), MONTH(trans_date), country

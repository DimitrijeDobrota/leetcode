(
    SELECT name AS results
    FROM MovieRating R
    LEFT JOIN Users U
    ON R.user_id = U.user_id
    GROUP BY R.user_id
    ORDER BY COUNT(*) DESC, U.name
    LIMIT 1
) UNION ALL (
    SELECT M.title
    FROM MovieRating R
    LEFT JOIN Movies M
    ON R.movie_id = M.movie_id
    WHERE YEAR(R.created_at) = 2020 AND MONTH(R.created_at) = 2
    GROUP BY R.movie_id
    ORDER BY AVG(R.rating) DESC, M.title
    LIMIT 1
)

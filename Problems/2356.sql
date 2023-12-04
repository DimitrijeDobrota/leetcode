SELECT teacher_id, COUNT(DISTINCT subject_ID) AS cnt
FROM Teacher
GROUP BY teacher_id

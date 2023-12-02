SELECT S.student_id, S.student_name, C.subject_name, COUNT(E.student_id) AS attended_exams
FROM Students S
CROSS JOIN Subjects C
LEFT JOIN Examinations E
ON S.student_id = E.student_id AND
   C.subject_name = E.subject_name
GROUP BY S.student_id, C.subject_name
ORDER BY S.student_id, C.subject_name


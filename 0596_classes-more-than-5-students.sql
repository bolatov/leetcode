# Write your MySQL query statement below
SELECT tbl.class
FROM (
    SELECT c.class, count(DISTINCT(c.student)) cnt
    FROM courses c
    GROUP BY c.class
    ) tbl
WHERE tbl.cnt >= 5
    

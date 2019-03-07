# Write your MySQL query statement below
SELECT e.Email
FROM (
    SELECT p.Email, count(p.Email) cnt
    FROM Person p
    GROUP BY p.Email
) e
WHERE e.cnt > 1

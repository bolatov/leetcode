# Write your MySQL query statement below
SELECT c.Name Customers
FROM Customers c
WHERE c.Id NOT IN (
    SELECT o.CustomerId
    FROM (
        SELECT 
            ord.CustomerId, 
            count(*) as cnt
        FROM Orders ord
        GROUP BY ord.CustomerId
    ) o
    WHERE o.cnt > 0
)

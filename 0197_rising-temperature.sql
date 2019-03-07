# Write your MySQL query statement below
SELECT w.Id
FROM Weather w
    WHERE w.Id IN (
        SELECT w.Id
        FROM Weather y 
            WHERE subdate(w.RecordDate, 1) = y.RecordDate AND y.Temperature < w.Temperature
    )

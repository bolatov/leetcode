# Write your MySQL query statement below
UPDATE salary
SET sex = 
CASE
    WHEN sex = 'f' THEN 'm'
    WHEN sex = 'm' THEN 'f'
END
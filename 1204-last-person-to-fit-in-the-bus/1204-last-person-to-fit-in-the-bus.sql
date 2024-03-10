# Write your MySQL query statement below
SELECT person_name 
FROM (
    select 
        person_name,
        turn,
        SUM(weight) OVER (ORDER BY turn) AS total_weight
    FROM Queue
) AS q1
WHERE total_weight <= 1000 
ORDER BY turn DESC
LIMIT 1;

-- WITH cte AS (
--     SELECT person_name,
--     SUM(weight) OVER (ORDER BY turn) AS total_weight
--     FROM Queue
-- )
-- SELECT person_name
-- FROM cte
-- WHERE total_weight <= 1000
-- ORDER BY total_weight DESC
-- LIMIT 1;
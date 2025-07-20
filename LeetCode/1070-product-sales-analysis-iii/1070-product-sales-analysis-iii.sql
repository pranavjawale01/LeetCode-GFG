# Write your MySQL query statement below
SELECT s.product_id, s.year AS first_year, s.quantity, s.price
FROM Sales s
WHERE (s.product_id, s.year) IN (
    SELECT s.product_id, min(s.year)
    FROM Sales s
    GROUP BY s.product_id
)
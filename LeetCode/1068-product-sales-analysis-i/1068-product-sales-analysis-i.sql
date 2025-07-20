# Write your MySQL query statement below
SELECT B.product_name, A.year, A.price
FROM Sales A 
INNER JOIN Product B ON A.product_id = B.product_id;
# Write your MySQL query statement below
SELECT p1.product_id, IFNULL(ROUND(SUM(units * price) / SUM(units), 2), 0)
AS average_price
FROM Prices p1
LEFT JOIN UnitsSold u1
ON u1.purchase_date BETWEEN p1.start_date AND p1.end_date
AND u1.product_id = p1.product_id
GROUP BY p1.product_id
/* Write your PL/SQL query statement below */
SELECT p.product_name, SUM(o.unit) unit 
FROM Products p, Orders o
WHERE p.product_id = o.product_id
AND o.order_date >= to_date('2020-02-01', 'YYYY-MM-DD')
AND o.order_date <= to_date('2020-02-29', 'YYYY-MM-DD')
GROUP BY p.product_name
HAVING SUM(o.unit) >= 100
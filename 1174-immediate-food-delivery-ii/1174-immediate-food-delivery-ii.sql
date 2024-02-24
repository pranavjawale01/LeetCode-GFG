/* Write your PL/SQL query statement below */
WITH temp AS (SELECT ROW_NUMBER() OVER (PARTITION BY customer_id ORDER BY order_date) AS row_num,
customer_id, order_date, customer_pref_delivery_date FROM delivery)

SELECT ROUND(CAST(SUM(CASE WHEN row_num = 1 AND order_date = customer_pref_delivery_date THEN 1 ELSE 0 END)
AS BINARY_DOUBLE) / SUM(CASE WHEN row_num = 1 THEN 1 ELSE 0 END) * 100, 2) AS immediate_percentage
FROM temp
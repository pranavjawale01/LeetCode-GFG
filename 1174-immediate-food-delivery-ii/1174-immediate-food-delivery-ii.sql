# Write your MySQL query statement below
WITH cte AS (
    SELECT DISTINCT customer_id, order_date, customer_pref_delivery_date
    FROM delivery
    WHERE concat(customer_id, '|', order_date) IN 
    (SELECT CONCAT(customer_id,'|', min(order_date))
        FROM delivery GROUP BY customer_id
    )
)

SELECT ROUND(COUNT(cte2.customer_id) / COUNT(cte1.customer_id) * 100, 2) AS immediate_percentage
FROM cte cte1 LEFT JOIN cte cte2
ON cte1.customer_id = cte2.customer_id
AND cte1.order_date = cte2.customer_pref_delivery_date
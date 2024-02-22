-- Write your PostgreSQL query statement below
SELECT
    query_name,
    ROUND(AVG(CAST(rating AS DECIMAL) / position), 2) AS quality,
    ROUND(SUM(CASE WHEN rating < 3 THEN 1 else 0 END) * 100::DECIMAL / count(*)::DECIMAL, 2) AS  poor_query_percentage
FROM queries
WHERE query_name IS NOT NULL
GROUP BY query_name
ORDER BY 1 DESC;
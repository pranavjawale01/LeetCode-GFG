SELECT 
    a.query_name, 
    ROUND(AVG(a.rating / a.position), 2) AS quality, 
    ROUND(SUM(CASE WHEN a.rating < 3 THEN 1 ELSE 0 END) * 100.0 / COUNT(a.rating), 2) AS poor_query_percentage
FROM Queries a
WHERE a.query_name IS NOT NULL
GROUP BY a.query_name;
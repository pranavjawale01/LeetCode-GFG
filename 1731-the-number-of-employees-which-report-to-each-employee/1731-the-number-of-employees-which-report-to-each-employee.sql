-- Write your PostgreSQL query statement below
SELECT
    m.employee_id,
    m.name,
    COUNT(e.employee_id) AS reports_count,
    ROUND(AVG(e.age)) AS average_age
FROM Employees m
LEFT JOIN Employees e ON m.employee_id = e.reports_to
GROUP BY m.employee_id, m.name
HAVING COUNT(e.employee_id) > 0
ORDER BY employee_id
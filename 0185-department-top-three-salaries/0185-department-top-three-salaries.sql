-- Write your PostgreSQL query statement below
SELECT departmentname AS department, name AS employee, salary 
FROM (
    SELECT d.name AS departmentname, e.*,
    dense_rank() OVER (
        PARTITION BY departmentid 
        ORDER BY SALARY DESC
    ) AS rnk
    FROM employee e 
    JOIN department d
    ON e.departmentid = d.id
)
WHERE rnk <= 3;
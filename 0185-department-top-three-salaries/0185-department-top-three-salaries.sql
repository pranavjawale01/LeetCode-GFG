# Write your MySQL query statement below
SELECT b.name AS Department, 
       a.name AS Employee, 
       a.salary AS Salary
FROM Employee AS a
INNER JOIN Department AS b ON a.departmentId = b.id
WHERE 3 > (
    SELECT COUNT(DISTINCT c.salary) 
    FROM Employee AS c
    WHERE c.salary > a.salary AND c.departmentId = a.departmentId
);
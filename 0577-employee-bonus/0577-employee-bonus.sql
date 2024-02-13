-- Write your PostgreSQL query statement below
SELECT e.NAME,b.BONUS FROM 
employee e LEFT OUTER JOIN bonus b
ON e.empId =b.empId 
WHERE b.bonus <1000 OR bonus IS NULL
/* Write your PL/SQL query statement below */
SELECT MAX(salary) AS SecondHighestSalary
FROM Employee
WHERE salary < (
    SELECt MAX(salary) 
    FROM Employee
);
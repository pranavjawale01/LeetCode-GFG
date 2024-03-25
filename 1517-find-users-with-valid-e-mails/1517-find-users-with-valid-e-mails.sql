-- Write your PostgreSQL query statement below
SELECT * 
FROM Users
WHERE regexp_like(mail, '^[A-Za-z]{1}[A-Za-z0-9_.-]*@leetcode[.]com$');
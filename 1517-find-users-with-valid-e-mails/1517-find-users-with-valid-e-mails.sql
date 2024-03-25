# Write your MySQL query statement below
SELECT * FROM
Users
WHERE mail regexp '^[a-zA-Z][a-zA-Z0-9_.-]*@leetcode[.]com$';
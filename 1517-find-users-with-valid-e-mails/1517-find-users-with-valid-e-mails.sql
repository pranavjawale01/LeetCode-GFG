/* Write your PL/SQL query statement below */
SELECT *
FROM Users
WHERE REGEXP_LIKE (mail, '^[a-zA-Z][a-zA-Z0-9_.-]*@leetcode[.]com$')
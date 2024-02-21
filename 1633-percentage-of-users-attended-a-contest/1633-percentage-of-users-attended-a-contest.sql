# Write your MySQL query statement below
SELECT r.contest_id , ROUND((COUNT(DISTINCT user_id) * 100 / (SELECT COUNT(u.user_id) FROM Users u)), 2) AS percentage
FROM Register r
GROUP BY contest_id
ORDER BY percentage DESC, contest_id ASC;
# Write your MySQL query statement below
select name
from Customer
where referee_id <> 2 or coalesce(referee_id, 0) = 0;
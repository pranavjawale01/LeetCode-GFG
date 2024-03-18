/* Write your PL/SQL query statement below */
with t1 as (
select
    departmentId,
    e.name as Employee,
    salary as Salary,
    dense_rank() over (partition by departmentId order by salary desc) as ranks
from Employee e
)
select
    d.name as Department,
    Employee,
    Salary
from t1
join Department d
    on t1.departmentId = d.id
where ranks <=3
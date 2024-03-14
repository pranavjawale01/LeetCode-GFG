# Write your MySQL query statement below
WITH MOV AS 
(
    select rat.* , us.name as "user" , mv.title as "movie" 
    from MovieRating as rat , Users as us , Movies as mv 
    where rat.user_id=us.user_id and mv.movie_id=rat.movie_id
)

select a.user as "results" 
from (select *,count(user) over(partition by user) as results 
        from MOV order by results desc, user asc limit 1) 
    as a 
union all
select b.movie as "results" 
from (select *,avg(rating) over(partition by movie) as results 
        from MOV where MONTH(created_at)=02 and YEAR(created_at)=2020 
        order by results desc, movie asc limit 1)
     as b
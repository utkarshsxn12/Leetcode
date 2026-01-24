# Write your MySQL query statement below
select * from cinema c where c.id % 2 = 1 AND c.description!='boring'
order by c.rating desc;
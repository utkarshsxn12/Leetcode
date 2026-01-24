# Write your MySQL query statement below
Select class from courses group by class having 
count(student)>4;
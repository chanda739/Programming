# Write your MySQL query statement below
select Emp.employee_id
from
(select * from employees left join salaries using (employee_id)
union
select * from employees right join salaries using (employee_id)) AS Emp
where Emp.name is null or Emp.salary is null
order by employee_id;

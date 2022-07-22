# Write your MySQL query statement below
update Salary
SET 
    sex = CASE sex
        WHEN 'm' then 'f'
        ELSE 'm'
    END;

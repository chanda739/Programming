# Write your MySQL query statement below
SELECT Customers.name as "Customers"
FROM Customers 
WHERE Customers.id not in(select customerId FROM Orders);

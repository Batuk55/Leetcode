# Write your MySQL query statement below
SELECT e.name AS Employee
FROM Employee AS e
JOIN Employee AS m
ON e.managerId = m.id
WHERE m.salary IS NOT NULL AND e.salary > m.salary;
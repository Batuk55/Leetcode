# Write your MySQL query statement below
-- SELECT firstName, lastName, city, state FROM (
--     SELECT *
--     FROM Person AS p
--     LEFT JOIN Address AS a
--     ON p.personId = a.personId
-- )AS temp;

SELECT p.firstName, p.lastName, a.city, a.state
FROM Person as p
LEFT JOIN Address as a
ON p.personId = a.personId;
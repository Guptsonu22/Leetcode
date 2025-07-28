-- CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
-- BEGIN
--  DECLARE offset_val INT;
--   SET offset_val = N - 1;
--   RETURN (
--       # Write your MySQL query statement below.
--         SELECT DISTINCT salary
--     FROM Employee
--     ORDER BY salary DESC
--     LIMIT 1 OFFSET offset_val

--   );
-- END


CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
set n=n-1;
  RETURN (
      # Write your MySQL query statement below.
select distinct salary
from Employee
order by Salary desc
limit 1 offset N
  );
END

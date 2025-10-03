SELECT e.employee_id
FROM (
    SELECT employee_id FROM Employees
    UNION
    SELECT employee_id FROM Salaries
) e
LEFT JOIN Employees emp
  ON e.employee_id = emp.employee_id
LEFT JOIN Salaries sal
  ON e.employee_id = sal.employee_id
WHERE emp.employee_id IS NULL OR sal.employee_id IS NULL
ORDER BY e.employee_id;

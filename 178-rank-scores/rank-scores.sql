-- # Write your MySQL query statement below
-- SELECT 
--     score,
--     DENSE_RANK() OVER (ORDER BY score DESC) AS 'rank'
-- FROM Scores
-- ORDER BY score DESC;

SELECT score,
DENSE_RANK() OVER(ORDER BY score DESC) as "rank"
FROM Scores

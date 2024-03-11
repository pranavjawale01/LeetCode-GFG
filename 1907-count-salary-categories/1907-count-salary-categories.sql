# Write your MySQL query statement below

SELECT 
    categories.category,
    COUNT(accounts.account_id) AS accounts_count
FROM 
    (SELECT 'Low Salary' AS category
     UNION ALL
     SELECT 'Average Salary' AS category
     UNION ALL
     SELECT 'High Salary' AS category) AS categories
LEFT JOIN 
    accounts ON
    (categories.category = 
        IF(accounts.income < 20000, 'Low Salary', 
            IF(accounts.income BETWEEN 20000 AND 50000, 'Average Salary', 'High Salary')
        )
    )
GROUP BY 
    categories.category;

-- SELECT 'Low Salary' as category, IFNULL(COUNT(*), 0) as accounts_count
-- FROM Accounts
-- WHERE income < 20000
-- UNION 
-- SELECT 'Average Salary' , IFNULL(COUNT(*), 0) as accounts_count
-- FROM Accounts
-- WHERE income BETWEEN 20000 AND 50000
-- UNION 
-- SELECT 'High Salary' , IFNULL(COUNT(*), 0) as accounts_count
-- FROM Accounts
-- WHERE income > 50000
-- ORDER BY accounts_count DESC;
import pandas as pd

def count_salary_categories(accounts: pd.DataFrame) -> pd.DataFrame:
    dic = {'Low Salary': 0, 'Average Salary': 0, 'High Salary': 0 }
    for i in accounts['income']:
        if i < 20000:
            dic['Low Salary'] +=1
        elif 20000 <= i <= 50000:
            dic['Average Salary'] +=1
        elif i > 50000:
            dic['High Salary'] +=1
    return pd.DataFrame(dic.items(), columns=['category', 'accounts_count'])
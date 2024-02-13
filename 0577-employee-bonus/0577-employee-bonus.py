import pandas as pd

def employee_bonus(employee: pd.DataFrame, bonus: pd.DataFrame) -> pd.DataFrame:
    select = employee.merge(bonus, on='empId', how='left')
    result = select[['name', 'bonus']]
    result = result[(result['bonus'] < 1000) | (result['bonus'].isnull())]
    return result
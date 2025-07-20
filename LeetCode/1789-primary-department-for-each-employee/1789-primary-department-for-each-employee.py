import pandas as pd

def find_primary_department(employee: pd.DataFrame) -> pd.DataFrame:
    df1 = employee[employee['primary_flag']=='Y'][['employee_id', 'department_id']]
    df2 = employee[employee.groupby('employee_id',as_index=False)['employee_id'].transform('size') == 1][['employee_id', 'department_id']]
    return pd.concat([df1, df2], ignore_index=True).drop_duplicates()
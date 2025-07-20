import pandas as pd

def project_employees_i(project: pd.DataFrame, employee: pd.DataFrame) -> pd.DataFrame:
    select = pd.merge(project, employee, on='employee_id', how='inner')
    select = select.groupby('project_id')['experience_years'].mean().round(2).reset_index()
    select = select.rename(columns={'experience_years': 'average_years'})
    return select
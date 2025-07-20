import pandas as pd

def find_managers(employee: pd.DataFrame) -> pd.DataFrame:
    
    manager_report_count = employee.groupby('managerId').size().reset_index(name='directReports')
    
    result = manager_report_count[manager_report_count['directReports'] >= 5]
    
    result = result.merge(employee[['id', 'name']], left_on='managerId', right_on='id', how='inner')
   
    result = result[['name']]
    
    return result
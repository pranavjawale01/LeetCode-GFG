import pandas as pd

def find_customers(visits: pd.DataFrame, transactions: pd.DataFrame) -> pd.DataFrame:
    select = visits.merge(transactions, how='left', on='visit_id')
    result = select.query('amount.isna()')
    return result.groupby(['customer_id'])['visit_id'].count().rename('count_no_trans').reset_index()
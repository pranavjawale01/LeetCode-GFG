import pandas as pd

def find_customers(visits: pd.DataFrame, transactions: pd.DataFrame) -> pd.DataFrame:
    df = visits.merge(transactions, how = 'left', on = 'visit_id')
    df = df[df['transaction_id'].isna()]
    df = df.groupby('customer_id')['visit_id'].count().reset_index()
    return df.rename(columns = {'visit_id' : 'count_no_trans'})
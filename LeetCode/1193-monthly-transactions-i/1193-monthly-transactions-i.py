import pandas as pd
import numpy as np

def monthly_transactions(transactions: pd.DataFrame) -> pd.DataFrame:
    transactions['month'] = transactions['trans_date'].dt.strftime("%Y-%m")
    transactions['country'].fillna('null',inplace=True)
    transactions['approved'] = np.where(
        transactions['state'] == 'approved',transactions['amount'],nan
    )
    transactions = transactions.groupby(['month','country'],as_index=False).agg(
        trans_count=('amount','count'),
        approved_count=('approved','count'),
        trans_total_amount=('amount','sum'),
        approved_total_amount=('approved','sum')
    )
    transactions['country'].replace('null',nan,inplace=True)
    return transactions
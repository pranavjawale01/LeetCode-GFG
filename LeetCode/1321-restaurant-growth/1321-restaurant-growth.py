import pandas as pd

def restaurant_growth(customer: pd.DataFrame) -> pd.DataFrame:
    customer.sort_values('visited_on', inplace=True)
    customer = customer.groupby('visited_on')['amount'].sum().reset_index()
    customer['average_amount'] = customer['amount'].rolling(window=7).mean().round(2)
    customer['amount'] = customer['amount'].rolling(window=7).sum().round(2)
    return customer.dropna()
import pandas as pd

def find_customers(customer: pd.DataFrame, product: pd.DataFrame) -> pd.DataFrame:
    df = customer.drop_duplicates(keep = 'first').groupby('customer_id').count().reset_index()
    return df[df.product_key == len(product)][['customer_id']]
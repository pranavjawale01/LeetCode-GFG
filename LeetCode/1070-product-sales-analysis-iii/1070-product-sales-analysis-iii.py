import pandas as pd

def sales_analysis(sales: pd.DataFrame, product: pd.DataFrame) -> pd.DataFrame:
    df1 = sales[['product_id', 'year']].groupby('product_id').min('year')
    df2 = sales.merge(df1, how='inner', on=['product_id', 'year']).rename(columns={'year':'first_year'})
    return df2[['product_id', 'first_year', 'quantity', 'price']]
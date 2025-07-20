import pandas as pd

def sales_analysis(sales: pd.DataFrame, product: pd.DataFrame) -> pd.DataFrame:
    select = sales.merge(product, on='product_id', how='inner')
    result = select[['product_name', 'year', 'price']]
    return result
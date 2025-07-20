import pandas as pd

def price_at_given_date(products: pd.DataFrame) -> pd.DataFrame:
    ids = pd.DataFrame({'product_id': products['product_id'].unique()})
    
    threshold = pd.to_datetime('2019-08-16')
    products = products.loc[products['change_date'] <= threshold]
    products.sort_values(by='change_date', inplace=True)
    products.drop_duplicates(subset='product_id', keep='last', inplace=True)
    
    output = pd.merge(products, ids, on='product_id', how='right')
    output = output.rename(columns={'new_price': 'price'}).fillna(10)
    return output[['product_id', 'price']]
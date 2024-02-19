import pandas as pd

def average_selling_price(prices: pd.DataFrame, units_sold: pd.DataFrame) -> pd.DataFrame:
    price_join_units = prices.merge(right=units_sold, how='left', on='product_id')
    temp = price_join_units[(price_join_units['purchase_date'] >= price_join_units['start_date']) & (price_join_units['purchase_date'] <= price_join_units['end_date'])][['product_id','price','units']]
    temp['cost'] = temp['price']*temp['units']
    temp2 = temp.groupby('product_id').sum().reset_index()
    temp2['average_price'] = round(temp2['cost']/temp2['units'],2)
    unique_product = pd.DataFrame(columns=['product_id'], data=prices['product_id'].unique())
    return unique_product.merge(right=temp2, how='left', on ='product_id')[['product_id','average_price']].fillna(0)
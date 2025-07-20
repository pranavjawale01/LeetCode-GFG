import pandas as pd

def immediate_food_delivery(delivery: pd.DataFrame) -> pd.DataFrame:
    df = delivery.sort_values(['customer_id','order_date'], ascending=[True, True]).drop_duplicates(subset=['customer_id'], keep='first')
    return pd.DataFrame({'immediate_percentage':[round(df[df['order_date'] == df['customer_pref_delivery_date']].shape[0] * 100 / len(df), 2)]})
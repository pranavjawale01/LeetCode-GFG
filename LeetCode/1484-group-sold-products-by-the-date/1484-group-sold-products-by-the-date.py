import pandas as pd

def categorize_products(activities: pd.DataFrame) -> pd.DataFrame:
    df = activities.groupby('sell_date', as_index=False)['product'].apply(lambda x: ','.join(sorted(x.unique())))
    df['num_sold'] = df['product'].apply(lambda x: len(x.split(',')))
    df = df.rename(columns={'product': 'products'})
    return df[['sell_date', 'num_sold', 'products']]
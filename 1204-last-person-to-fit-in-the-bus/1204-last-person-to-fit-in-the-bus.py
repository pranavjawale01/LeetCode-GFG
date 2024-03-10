import pandas as pd

def last_passenger(df: pd.DataFrame) -> pd.DataFrame:
    df = df.sort_values(by='turn')
    df['total'] = df['weight'].rolling(window=len(df),min_periods=1).sum()
    return df[df['total'] <= 1000].tail(1)[['person_name']]
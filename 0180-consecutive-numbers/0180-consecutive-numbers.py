import pandas as pd

def consecutive_numbers(logs: pd.DataFrame) -> pd.DataFrame:
    logs['lag'] = logs['num'].shift(-1)
    logs['lead']=logs['num'].shift(1)
    filt=(logs['num']==logs['lag']) & (logs['num']==logs['lead'])
    return logs.loc[filt, ['num']].rename(columns={'num':'ConsecutiveNums'}).drop_duplicates()
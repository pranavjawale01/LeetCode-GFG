import pandas as pd

def confirmation_rate(signups: pd.DataFrame, confirmations: pd.DataFrame) -> pd.DataFrame:
    confirm=pd.DataFrame(confirmations) 
    mask=(confirm['action']=="confirmed") 
    confirm=confirm.loc[mask]
    confirm_count = confirm.groupby('user_id').size().reset_index(name='confirm_count')
    total_count=confirmations.groupby('user_id').size().reset_index(name='confirm_count')
    df = signups.merge(total_count, how = 'left'
               ).merge(confirm_count , how = 'left', on = 'user_id')

    df['confirmation_rate'] =  ((df.confirm_count_y)/ (df.confirm_count_x)).round(2)   

    return df.iloc[:,[0,4]].fillna(0)
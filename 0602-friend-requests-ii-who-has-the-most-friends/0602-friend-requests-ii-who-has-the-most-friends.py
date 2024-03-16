import pandas as pd

def most_friends(request_accepted: pd.DataFrame) -> pd.DataFrame:

    all_friends = pd.concat([request_accepted['requester_id'], request_accepted['accepter_id']])
    
    cnt=all_friends.value_counts().reset_index(name='num').rename(columns={'index':'id'})    

    return cnt.loc[cnt['num'] == cnt['num'].max()]
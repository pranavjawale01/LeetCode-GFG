import pandas as pd

def gameplay_analysis(activity: pd.DataFrame) -> pd.DataFrame:
    activity['first']= activity.groupby('player_id').event_date.transform(min)
    activity_day2= activity.loc[ activity['first']+ pd.DateOffset(1)== activity['event_date']]
    answer= len(activity_day2)/ (activity['player_id'].nunique())
    return pd.DataFrame({"fraction":[ round( answer, 2)]})
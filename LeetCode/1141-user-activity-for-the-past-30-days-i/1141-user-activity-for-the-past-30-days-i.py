import pandas as pd

def user_activity(activity: pd.DataFrame) -> pd.DataFrame:
    end_date = pd.to_datetime('2019-07-27')
    start_date = end_date - pd.DateOffset(days=29)
    result = activity[(activity['activity_date'] >= start_date) & (activity['activity_date'] <= end_date)]
    result = result.groupby('activity_date')['user_id'].nunique().reset_index()
    result = result.rename(columns={'activity_date': 'day', 'user_id': 'active_users'})
    return result
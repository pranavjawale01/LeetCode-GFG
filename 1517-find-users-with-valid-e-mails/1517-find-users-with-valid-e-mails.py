import pandas as pd

def valid_emails(users: pd.DataFrame) -> pd.DataFrame:
    return users[users['mail'].str.match("^[A-Za-z][A-Za-z0-9_.-]{0,}@leetcode[.]com{1}$")].sort_values(by = 'user_id')
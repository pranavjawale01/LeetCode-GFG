import pandas as pd

def invalid_tweets(tweets: pd.DataFrame) -> pd.DataFrame:
    select = tweets[tweets['content'].str.len() > 15]
    return select[['tweet_id']]
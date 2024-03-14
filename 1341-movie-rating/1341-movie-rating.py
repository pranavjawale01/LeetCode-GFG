import pandas as pd

def movie_rating(df1: pd.DataFrame, df2: pd.DataFrame, df3: pd.DataFrame) -> pd.DataFrame:
    x = pd.merge(left=df1,right=df3,on='movie_id',how='outer')
    df = pd.merge(left=x,right=df2,on='user_id',how='outer')
    df['count_mov'] = df.groupby('name')['title'].transform('count')
    df['rating_feb'] = df[(df['created_at'] >= '2020-02-01')&(df['created_at'] <= '2020-02-29')].groupby('movie_id')['rating'].transform('mean')
    x = df[df['count_mov'] == df['count_mov'].max()][['name']].drop_duplicates().sort_values(by='name').reset_index(drop=True).iloc[[0]]
    y = df[df['rating_feb'] == df['rating_feb'].max()][['title']].drop_duplicates().sort_values(by='title').reset_index(drop=True).iloc[[0]]
    res = pd.concat([x,y])
    res['results'] = res['name'].fillna('') + res['title'].fillna('')
    return res[['results']]
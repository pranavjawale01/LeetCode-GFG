import pandas as pd

def article_views(views: pd.DataFrame) -> pd.DataFrame:
    select = views[views['author_id'] == views['viewer_id']]
    select = select['author_id'].unique()
    select = sorted(select)
    select = pd.DataFrame({'id': select})
    return select
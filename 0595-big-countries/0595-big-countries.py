import pandas as pd

def big_countries(world: pd.DataFrame) -> pd.DataFrame:
    select = World[(World['area'] >= 3000000) | (World['population'])]
    return select[['name', 'population', 'area']]
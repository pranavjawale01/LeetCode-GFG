import pandas as pd

def triangle_judgement(triangle: pd.DataFrame) -> pd.DataFrame:
    mask = (triangle['x'] + triangle['y'] > triangle['z']) & (triangle['z'] + triangle['y'] > triangle['x']) & (triangle['x'] + triangle['z'] > triangle['y'])
    triangle['Triangle'] = 'Yes'
    triangle.loc[~mask, 'Triangle'] = 'No'
    return triangle
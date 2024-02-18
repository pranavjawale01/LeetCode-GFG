import pandas as pd

def not_boring_movies(cinema: pd.DataFrame) -> pd.DataFrame:
    filtered_cinema = cinema[(cinema['description'] != 'boring') & (cinema['id'] % 2 != 0)]
    sorted_cinema = filtered_cinema.sort_values(by='rating', ascending=False)
    return sorted_cinema
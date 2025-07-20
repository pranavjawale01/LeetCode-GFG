import pandas as pd

def exchange_seats(seat: pd.DataFrame) -> pd.DataFrame:
    memory = ""
    try:
        for index, row in seat.iterrows():
            #odd 
            if index % 2 == 0:
                memory = row["student"]
                seat.loc[index, "student"] = seat.loc[index+1, "student"]
                seat.loc[index+1, "student"] = memory
    
        return seat
    except:
        return seat
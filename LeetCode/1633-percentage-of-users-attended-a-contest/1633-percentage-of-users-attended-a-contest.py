import pandas as pd

def users_percentage(users: pd.DataFrame, register: pd.DataFrame) -> pd.DataFrame:
    grouped = pd.DataFrame(register.groupby("contest_id")["user_id"].count().reset_index())
    grouped["percentage"] = round(grouped["user_id"] / len(users) * 100, 2)
    grouped = grouped[["contest_id", "percentage"]]
    return grouped.sort_values(by=["percentage", "contest_id"], ascending=[False, True])
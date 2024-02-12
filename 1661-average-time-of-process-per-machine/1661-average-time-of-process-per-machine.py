import pandas as pd

def get_average_time(activity: pd.DataFrame) -> pd.DataFrame:
    start_df = activity.loc[activity["activity_type"]=="start"]
    end_df = activity.loc[activity["activity_type"]=="end"]

    full_df = start_df.merge(end_df,how="inner",on=["machine_id","process_id"])
    full_df["processing_time"] = full_df["timestamp_y"] - full_df["timestamp_x"]

    grouped_df = full_df.groupby(by=["machine_id"]).agg({"processing_time":"mean"})
    grouped_df.reset_index(inplace=True)
    grouped_df["processing_time"] = grouped_df["processing_time"].round(3)

    return grouped_df
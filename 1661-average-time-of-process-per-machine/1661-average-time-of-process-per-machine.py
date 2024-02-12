import pandas as pd

def get_average_time(activity: pd.DataFrame) -> pd.DataFrame:
    start_activities = activity[activity['activity_type'] == 'start']
    end_activities = activity[activity['activity_type'] == 'end']
    merged_activities = pd.merge(start_activities, end_activities, on=['machine_id', 'process_id'])

    merged_activities['processing_time'] = merged_activities['timestamp_y'] - merged_activities['timestamp_x']

    average_time = merged_activities.groupby('machine_id')['processing_time'].mean().reset_index()

    # Round the average processing time to 3 decimal places
    average_time['processing_time'] = average_time['processing_time'].round(3)

    return average_time
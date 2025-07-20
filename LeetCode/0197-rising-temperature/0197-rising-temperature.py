def rising_temperature(weather: pd.DataFrame) -> pd.DataFrame:
    
    weather.sort_values(by='recordDate', ascending=True, inplace=True)

    weather['temperature_diff'] = weather['temperature'] - weather['temperature'].shift(1)
    
    weather['recordDate_diff'] = weather['recordDate'] - weather['recordDate'].shift(1)

    filter_rising_temperature = weather[(weather['temperature_diff'] > 0) & (weather['recordDate_diff'] == pd.Timedelta(days=1))]['id']
    
    result_df = pd.DataFrame(filter_rising_temperature)
 
    return result_df
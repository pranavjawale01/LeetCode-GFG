import pandas as pd

def consecutive_numbers(logs: pd.DataFrame) -> pd.DataFrame:
    prev_num = None
    rec = []
    count = 0
    for index,row in logs.iterrows():

        if row['num'] == prev_num and count<3:
            count = count+1
        elif row['num'] == prev_num and count>3:
            continue
        elif index==0:
            count = count+1
        else:
            count = 1
        if count==3 and row['num'] not in rec:
            rec.append(row['num'])
            
        prev_num = row['num']
    
    newdf = pd.DataFrame({'ConsecutiveNums':rec})
    return newdf
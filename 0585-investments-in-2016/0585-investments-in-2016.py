import pandas as pd

def find_investments(insurance: pd.DataFrame) -> pd.DataFrame:
    df = insurance
    df["lat_lon"] = df["lat"].astype("str") +"_" + df["lon"].astype("str")
    df1 = df[(df.duplicated(subset=["tiv_2015"], keep=False) & ~(df.duplicated(subset=["lat_lon"], keep=False)))]
    result = df1.agg("tiv_2016").sum()
    result_df = pd.DataFrame({
        "tiv_2016": [result]
    })
    return result_df
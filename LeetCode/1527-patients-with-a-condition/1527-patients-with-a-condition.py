import pandas as pd

def find_patients(patients: pd.DataFrame) -> pd.DataFrame:
    selected_patients = patients[patients['conditions'].str.contains(r'\bDIAB1', regex=True)]
    return selected_patients
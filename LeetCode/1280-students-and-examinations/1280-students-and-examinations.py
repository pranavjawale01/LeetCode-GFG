import pandas as pd

def students_and_examinations(students: pd.DataFrame, subjects: pd.DataFrame, examinations: pd.DataFrame) -> pd.DataFrame:

    two_df = students.merge(subjects, how='cross')

    exam_count = examinations.groupby(['student_id', 'subject_name']).agg(
        attended_exams=('subject_name', 'count')
    ).reset_index()
    
    all_df = two_df.merge(exam_count, on=['student_id', 'subject_name'], how='left')
    
    all_df['attended_exams'] = all_df['attended_exams'].fillna(0)
    all_df[['student_id', 'student_name', 'subject_name']] = all_df[['student_id', 'student_name', 'subject_name']].fillna(pd.NA)
    
    all_df = all_df.sort_values(by=['student_id', 'subject_name']).reset_index(drop=True)
    
    all_df = all_df[['student_id', 'student_name', 'subject_name', 'attended_exams']]
    
    return all_df
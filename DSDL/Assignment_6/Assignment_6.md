# Problem Statement 
```
Named PL/SQL Block: PL/SQL Stored Procedure and Stored Function.
Write a Stored Procedure namely proc_Grade for the categorization of students. If marks scored by students in examination is <=1500 and marks>=990 then students will be placed in distinction category if marks scored are  between  989 and900 category is first  class,  if  marks 899 n 825 category is Higher Second Class.
Write a PL/SQLblock to use procedures created with the above requirement. Stud_Marks(name, total_marks)              Result(Roll,Name, Class)
```

# Solution

1. Create Tables
```sql
CREATE TABLE STUDENT_MARKS_TABLE (
    STUDENT_NAME VARCHAR2(50),
    STUDENT_MARKS NUMBER
);

CREATE TABLE STUDENT_RESULT_TABLE (
    ROLL_NUMBER NUMBER,
    STUDENT_NAME VARCHAR2(50),
    GRADE VARCHAR2(20)
);
```

2. Create Procedure
```sql
CREATE OR REPLACE PROCEDURE calculate_grade(
    roll_number NUMBER,
    student_name VARCHAR2,
    student_marks NUMBER
) IS
    grade VARCHAR2(20);
BEGIN
    IF(student_marks <= 1500
    AND student_marks >= 990) THEN
        grade := 'Distinction';
    ELSIF(student_marks <= 989
    AND student_marks >= 825) THEN
        grade := 'First Class';
    ELSIF(student_marks <= 824
    AND student_marks >= 750) THEN
        grade := 'Higher Second';
    ELSIF(student_marks <= 749
    AND student_marks >= 600) THEN
        grade := 'Pass';
    ELSE
        grade := 'Fail';
    END IF;
    INSERT INTO student_marks_table VALUES(
        student_name,
        student_marks
    );
    INSERT INTO student_result_table VALUES(
        roll_number,
        student_name,
        grade
    );
END;
```
3. Sample Queries to populate tables
```sql
BEGIN
  calculate_grade(1, 'Atharva Baradkar', 900); 
  calculate_grade(2, 'Shivam Srivastava', 800);
  calculate_grade(3, 'Harsh Tayade', 1100);
  calculate_grade(4, 'Rohan Singh', 600);
  calculate_grade(5, 'Pratik Puri', 1300);
  calculate_grade(6, 'Siddhant Singh', 300);
END;
```
# Output

1. Marks Table


|STUDENT_NAME     |STUDENT_MARKS|
|-----------------|-------------|
|Atharva Baradkar |900          |
|Shivam Srivastava|800          |
|Harsh Tayade     |1100         |
|Rohan Singh      |600          |
|Pratik Puri      |1300         |
|Siddhant Singh   |300          |

2. Result Table

|ROLL_NUMBER      |STUDENT_NAME|GRADE        |
|-----------------|------------|-------------|
|1                |Atharva Baradkar|First Class  |
|2                |Shivam Srivastava|Higher Second|
|3                |Harsh Tayade|Distinction  |
|4                |Rohan Singh |Pass         |
|5                |Pratik Puri |Distinction  |
|6                |Siddhant Singh|Fail         |



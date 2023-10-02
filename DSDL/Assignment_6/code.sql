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
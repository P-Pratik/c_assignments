DECLARE
    n_roll_no      n_rollcall.roll_no%type;
    n_student_name n_rollcall.student_name%type;
    exist          NUMBER := 0;
    CURSOR cursor_rollcall IS
        SELECT
            roll_no,
            student_name
        FROM
            n_rollcall;
BEGIN
    OPEN cursor_rollcall;
    LOOP
        FETCH cursor_rollcall INTO n_roll_no, n_student_name;
        EXIT WHEN cursor_rollcall%notfound;
        SELECT
            COUNT(*) INTO exist
        FROM
            o_rollcall
        WHERE
            roll_no = n_roll_no;
        IF exist = 0 THEN
            INSERT INTO o_rollcall (
                roll_no,
                student_name
            ) VALUES (
                n_roll_no,
                n_student_name
            );
        END IF;
    END LOOP;
    CLOSE cursor_rollcall;
EXCEPTION
    WHEN OTHERS THEN
        ROLLBACK;
        dbms_output.put_line('An error occurred: ' || sqlerrm);
END;
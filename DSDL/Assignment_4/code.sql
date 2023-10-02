DECLARE
    user_roll_no      NUMBER;
    user_book_name    VARCHAR2(100);
    issue_date        DATE;
    v_status          VARCHAR2(255);
    current_date      DATE := trunc(sysdate);
    days_diff         NUMBER;
    fine_amt          NUMBER;

 -- Define user-defined exception
    overdue_exception exception;
    PRAGMA exception_init(overdue_exception, -20001);
BEGIN
    user_roll_no := &enter_roll_no;
    user_book_name := '&Enter_Book_Name';

    SELECT
        date_of_issue,
        status 
        INTO 
            issue_date,
            v_status
    FROM
        borrower
    WHERE
        roll_no = user_roll_no
        AND name_of_book = user_book_name;

    days_diff := current_date - issue_date;
    IF v_status = 'I' THEN
        IF days_diff <= 15 THEN
            fine_amt := 0;
        ELSIF days_diff <= 30 THEN
            fine_amt := 5 * (days_diff - 15);
        ELSE
            fine_amt := 5 * 15 + 50 * (days_diff - 30);
        END IF;
        IF fine_amt > 0 THEN
            INSERT INTO fine (
                roll_no,
                fined_date,
                amt
            ) VALUES (
                user_roll_no,
                current_date,
                fine_amt
            );
        END IF;

        UPDATE borrower
        SET
            status = 'R'
        WHERE
            roll_no = user_roll_no
            AND name_of_book = user_book_name;

        dbms_output.put_line('Book returned successfully.'||'Fine amount is Rs.'||fine_amt);

 -- Raise an exception if the book is not in 'I' status
    ELSE
        RAISE overdue_exception;
    END IF;
EXCEPTION
    WHEN no_data_found THEN
        dbms_output.put_line('Book details not found.');
    WHEN overdue_exception THEN
        dbms_output.put_line('Book has already been returned');
    WHEN OTHERS THEN
        dbms_output.put_line('An error occurred: ' || sqlerrm);
END;
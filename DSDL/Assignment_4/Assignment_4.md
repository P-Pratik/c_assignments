>[!NOTE]
>Change table names according to you

1. Creating Tables
```sql
CREATE TABLE BORROWER (
    ROLL_NO NUMBER PRIMARY KEY,
    NAME VARCHAR2(255),
    DATE_OF_ISSUE DATE,
    NAME_OF_BOOK VARCHAR2(255),
    STATUS VARCHAR2(50)
);

CREATE TABLE FINE (
    ROLL_NO NUMBER,
    FINED_DATE DATE,
    AMT NUMBER(10, 2),
    PRIMARY KEY (ROLL_NO),
    FOREIGN KEY (ROLL_NO) REFERENCES BORROWER(ROLL_NO)
);
```
2. Insert Some Dummy Values Into Table Borrower

some dummy data
```sql
insert into Borrower (ROLL_NO, NAME, DATE_OF_ISSUE, NAME_OF_BOOK, STATUS) values (1, 'Delmer Abbie', '06-Aug-2023', 'Konklab', 'I');
insert into Borrower (ROLL_NO, NAME, DATE_OF_ISSUE, NAME_OF_BOOK, STATUS) values (2, 'Row Sole', '15-Oct-2022', 'Flexidy', 'I');
insert into Borrower (ROLL_NO, NAME, DATE_OF_ISSUE, NAME_OF_BOOK, STATUS) values (3, 'Dael Riste', '11-Jun-2023', 'Treeflex', 'I');
insert into Borrower (ROLL_NO, NAME, DATE_OF_ISSUE, NAME_OF_BOOK, STATUS) values (4, 'Pegeen Coltherd', '02-Apr-2023', 'Treeflex', 'I');
insert into Borrower (ROLL_NO, NAME, DATE_OF_ISSUE, NAME_OF_BOOK, STATUS) values (5, 'Merwin Canwell', '10-Jan-2023', 'Zoolab', 'I');
insert into Borrower (ROLL_NO, NAME, DATE_OF_ISSUE, NAME_OF_BOOK, STATUS) values (6, 'Shelba Cuel', '13-Jul-2023', 'Bigtax', 'I');
insert into Borrower (ROLL_NO, NAME, DATE_OF_ISSUE, NAME_OF_BOOK, STATUS) values (7, 'Ellene Simon', '18-Dec-2022', 'Bitwolf', 'I');
insert into Borrower (ROLL_NO, NAME, DATE_OF_ISSUE, NAME_OF_BOOK, STATUS) values (8, 'Urbanus Donke', '12-Mar-2023', 'Veribet', 'I');
insert into Borrower (ROLL_NO, NAME, DATE_OF_ISSUE, NAME_OF_BOOK, STATUS) values (9, 'Wait Scheffel', '10-Oct-2022', 'Sonair', 'I');
insert into Borrower (ROLL_NO, NAME, DATE_OF_ISSUE, NAME_OF_BOOK, STATUS) values (10, 'Remy Plows', '01-Sep-2022', 'Stringtough', 'I');
```
3. PL/SQL block for \
A. Accept Roll_no and Name of Book from the user. \
B. Check the number of days (from date of issue).\
C. If days are between 15 to 30 then the fine amount will be Rs 5 per day.\
D. If no. of days>30, per day fine will be Rs 50 per day and for days less than 30, Rs. 5 per day.\
E. After submitting the book, status will change from I to R.\
F. if condition of fine is true, then details will be stored into fine table\
G. Also handles the exception by named exception handler or user defined exception handler\

```sql
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

        dbms_output.put_line('Book returned successfully.');

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
```

# Problem Statement
**Cursors** : (All types: Implicit, Explicit, Cursor FOR Loop, Parameterized Cursor)
Write a PL/SQL block of code using parameterized Cursor that will merge the data available in the newly created table N_Roll Call with the data available in the table O_RollCall. If the data in the first table already exist in the second table then that data should be skipped. <br>
Note: Instructor will frame the problem statement for writing PL/SQL block using all types of Cursors in line with the above statement.

# Solution

1. Create Tables

```sql
CREATE TABLE N_RollCall (
  roll_no NUMBER PRIMARY KEY,
  student_name VARCHAR2(50)
);

CREATE TABLE O_RollCall (
  roll_no NUMBER PRIMARY KEY,
  student_name VARCHAR2(50)
);
```

2. Fill Tables With Dummy Data

```sql
INSERT INTO N_RollCall VALUES (1, 'Pratik Puri');
INSERT INTO N_RollCall VALUES (2, 'Hemant Yadav');
INSERT INTO N_RollCall VALUES (3, 'Rahul Sharma');
INSERT INTO N_RollCall VALUES (4, 'Harsh Tayade');
INSERT INTO N_RollCall VALUES (5, 'Atharva B');
INSERT INTO N_RollCall VALUES (6, 'Siddhant K');

INSERT INTO O_RollCall VALUES (4, 'Harsh Tayade');
```

3. Initial Tables

**O_RollCall Table** <br>

|ROLL_NO|STUDENT_NAME                  |
|-------|------------------------------|
|4      |Harsh Tayade                  |

<br>

**N_RollCall Table** <br>

|ROLL_NO|STUDENT_NAME                  |
|-------|------------------------------|
|1      |Pratik Puri                   |
|2      |Hemant Yadav                  |
|3      |Rahul Sharma                  |
|4      |Harsh Tayade                  |
|5      |Atharva B                     |
|6      |Siddhant K                    |

1. PL/SQL Block for Cursor

```sql 
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
```


# Output

After running the PL/SQL Block, the **O_RollCall Table** will have the following data after successful execution <br>

>PL/SQL procedure successfully completed.

<br>

|ROLL_NO|STUDENT_NAME                  |
|-------|------------------------------|
|4      |Harsh Tayade                  |
|1      |Pratik Puri                   |
|2      |Hemant Yadav                  |
|3      |Rahul Sharma                  |
|5      |Atharva B                     |
|6      |Siddhant K                    |

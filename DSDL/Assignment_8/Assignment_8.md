# Problem Statement
Database Trigger (All Types: Row level and Statement level triggers, Before and After Triggers). Write a database trigger on the Library table. The System should keep track of the records that are being updated or deleted. The old value of updated or deleted records should be added in the Library_Audit table.

# Solution 

1. Creating Required Tables 

```sql
CREATE TABLE library_record (
    book_id NUMBER,
    title VARCHAR2(60),
    author VARCHAR2(60),
    published_year DATE,
    category VARCHAR(50),
    PRIMARY KEY (book_id)
);

CREATE TABLE library_audit (
    book_id NUMBER,
    title VARCHAR2(60),
    author VARCHAR2(60),
    published_year DATE,
    category VARCHAR(50),
    status VARCHAR(20),
    PRIMARY KEY (book_id)
);
```

2. Creating Trigger

```sql
CREATE OR REPLACE TRIGGER library_audit_trigger AFTER
    UPDATE OR DELETE ON library_record FOR EACH ROW
DECLARE
    action VARCHAR2(20);
BEGIN
    IF deleting THEN
        action := 'DELETE';
    ELSIF updating THEN
        action := 'UPDATE';
    END IF;
    INSERT INTO library_audit VALUES (
        :old.book_id,
        :old.title,
        :old.author,
        :old.published_year,
        :old.category,
        action
    );
END;
```

3. Populating Table

```sql
Insert into LIBRARY_RECORD VALUES (1,'The Hobbit','J.R.R. Tolkien',to_date('21-09-1937','dd-mm-yyyy'),'Fantasy');
Insert into LIBRARY_RECORD VALUES (2,'The Fellowship of the Ring','J.R.R. Tolkien',to_date('29-07-1954','dd-mm-yyyy'),'Fantasy');
Insert into LIBRARY_RECORD VALUES (3,'The Two Towers','J.R.R. Tolkien',to_date('11-11-1954','dd-mm-yyyy'),'Fantasy');
Insert into LIBRARY_RECORD VALUES (4,'The Return of the King','J.R.R. Tolkien',to_date('20-10-1955','dd-mm-yyyy'),'Fantasy');
Insert into LIBRARY_RECORD VALUES (5,'The Lion, the Witch and the Wardrobe','C.S. Lewis',to_date('16-10-1950','dd-mm-yyyy'),'Fantasy');
Insert into LIBRARY_RECORD VALUES (6,'Prince Caspian','C.S. Lewis',to_date('15-10-1951','dd-mm-yyyy'),'Fantasy');
Insert into LIBRARY_RECORD VALUES (7,'The Voyage of the Dawn Treader','C.S. Lewis',to_date('15-09-1952','dd-mm-yyyy'),'Fantasy');
```

4. Sample Queries to trigger the trigger

```sql
DELETE library_record
WHERE
    book_id = 1;


UPDATE library_record
SET
    category='Fiction'
WHERE
    book_id = 6;
```

# Output

1. Library Record Table

|BOOK_ID|TITLE                         |AUTHOR                     |PUBLISHED_YEAR|CATEGORY |
|-------|------------------------------|---------------------------|--------------|---------|
|2      |The Fellowship of the Ring    |J.R.R. Tolkien             |29-JUL-54     |Fantasy  |
|3      |The Two Towers                |J.R.R. Tolkien             |11-NOV-54     |Fantasy  |
|4      |The Return of the King        |J.R.R. Tolkien             |20-OCT-55     |Fantasy  |
|5      |The Lion, the Witch and the Wardrobe|C.S. Lewis                 |16-OCT-50     |Fantasy  |
|6      |Prince Caspian                |C.S. Lewis                 |15-OCT-51     |Fiction  |
|7      |The Voyage of the Dawn Treader|C.S. Lewis                 |15-SEP-52     |Fantasy  |

2. Audit Table

|BOOK_ID|TITLE                         |AUTHOR                     |PUBLISHED_YEAR|CATEGORY |STATUS|
|-------|------------------------------|---------------------------|--------------|---------|------|
|1      |The Hobbit                    |J.R.R. Tolkien             |21-SEP-37     |Fantasy  |DELETE|
|6      |Prince Caspian                |C.S. Lewis                 |15-OCT-51     |Fantasy  |UPDATE|

>[!NOTE]
>Replace `<TABLENAME>` with your TableName


1. Create Table if not created
```sql

CREATE TABLE <TABLENAME> (RADIUS NUMBER, AREA NUMBER)
--
```

2. For Inserting Areas of circle's with radius (1-9)
```sql
DECLARE
    V_RADIUS NUMBER;
    V_AREA   NUMBER;
BEGIN
    FOR V_RADIUS IN 1..9 LOOP
        V_AREA := 3.14159 * V_RADIUS * V_RADIUS;
        INSERT INTO <TABLENAME> (
            RADIUS,
            AREA
        ) VALUES (
            V_RADIUS,
            V_AREA
        );
    END LOOP;
    DBMS_OUTPUT.PUT_LINE('Calculation and insertion completed');
END;
```

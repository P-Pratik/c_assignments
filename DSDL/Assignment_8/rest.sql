-- CREATE TABLE library_record (
--     book_id NUMBER,
--     title VARCHAR2(60),
--     author VARCHAR2(60),
--     published_year DATE,
--     category VARCHAR(50),
--     PRIMARY KEY (book_id)
-- );

-- CREATE TABLE library_audit (
--     book_id NUMBER,
--     title VARCHAR2(60),
--     author VARCHAR2(60),
--     published_year DATE,
--     category VARCHAR(50),
--     status VARCHAR(20),
--     PRIMARY KEY (book_id)
-- );

-- Insert into LIBRARY_RECORD VALUES (1,'The Hobbit','J.R.R. Tolkien',to_date('21-09-1937','dd-mm-yyyy'),'Fantasy');
-- Insert into LIBRARY_RECORD VALUES (2,'The Fellowship of the Ring','J.R.R. Tolkien',to_date('29-07-1954','dd-mm-yyyy'),'Fantasy');
-- Insert into LIBRARY_RECORD VALUES (3,'The Two Towers','J.R.R. Tolkien',to_date('11-11-1954','dd-mm-yyyy'),'Fantasy');
-- Insert into LIBRARY_RECORD VALUES (4,'The Return of the King','J.R.R. Tolkien',to_date('20-10-1955','dd-mm-yyyy'),'Fantasy');
-- Insert into LIBRARY_RECORD VALUES (5,'The Lion, the Witch and the Wardrobe','C.S. Lewis',to_date('16-10-1950','dd-mm-yyyy'),'Fantasy');
-- Insert into LIBRARY_RECORD VALUES (6,'Prince Caspian','C.S. Lewis',to_date('15-10-1951','dd-mm-yyyy'),'Fantasy');
-- Insert into LIBRARY_RECORD VALUES (7,'The Voyage of the Dawn Treader','C.S. Lewis',to_date('15-09-1952','dd-mm-yyyy'),'Fantasy');


-- DELETE library_record
-- WHERE
--     book_id = 1;

-- UPDATE library_record
-- SET
--     category='Fiction'
-- WHERE
--     book_id = 6;

select * from library_record;
select * from library_audit;

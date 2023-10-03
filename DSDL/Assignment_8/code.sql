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
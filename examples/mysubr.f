      SUBROUTINE MYSUBR( N )

      INTEGER  N

      EXTERNAL FOO, DUMMY

      IF( N .GT. 1 ) THEN
         CALL FOO( N-1 )
      ELSE
         CALL DUMMY
      END IF

      END

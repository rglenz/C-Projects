; Char Count
; A subroutine called by main that recursively find the number of occurrences of that character within that string
; Kalen Goo and Ray Lenz

            .ORIG x3300

            ; Callee setup
CHARCT      ADD R6, R6, #-1         ; Allocate space for the return value
            ADD R6, R6, #-1
            STR R7, R6, #0          ; Push return address onto RTS
            ADD R6, R6, #-1
            STR R5, R6, #0          ; Push dynamic link onto RTS
            ADD R5, R6, #-1         ; Set R5 to point to the base of the locals

            ; int result;
            ; int match;
            ADD R6, R6, #-2         ; Allocates space for local variables (result and match)


            ; if (*str == '\0');
            ADD R0, R5, #4          ; Put address of str into R0
            LDR R0, R0, #0          ; Load the address of str into R0 (from main)
            LDR R0, R0, #0          ; Load the value of str into R0
            Brnp NOTNULL

            ; result = 0
            STR R0, R5, #0
            Brnzp CALLEET

            ; else
            ; match = *str - key;
NOTNULL     ADD R1, R5, #5           ; Put address of key into R1
            LDR R1, R1, #0           ; Put value of key into R1
            NOT R1, R1               ; Flip key
            ADD R1, R1, #1
            ADD R0, R0, R1           ; match = *str - key;
            STR R0, R5, #-1          ; Store match in memory

            ; if (match == 0)
            Brnp RES0

            ; result = 1;
            AND R0, R0, #0           ; Clear R0
            ADD R0, R0, #1
            STR R0, R5, #0           ; result = 1
            Brnzp RECUR

            ; else match != 0
            ; result = 0
RES0        AND R0, R0, #0           ; Clear R0
            STR R0, R5, #0           ; result = 0

            ; charCount(str + 1, key);
            ; caller setup
RECUR       ADD R0, R5, #5          ; Get address of key into R0
            LDR R0, R0, #0          ; Get value of key into R0
            ADD R6, R6, #-1         ; Move stack pointer
            STR R0, R6, #0          ; Push key onto stack

            ADD R0, R5, #4          ; Get address of str into R0
            LDR R0, R0, #0          ; Load value of str into R0
            ADD R0, R0, #1          ; str + 1
            ADD R6, R6, #-1         ; Move stack pointer
            STR R0, R6, #0          ; Push key onto stack
            JSR CHARCT              ; Recursively call charCount

            ; result += charCount(str + 1, key);
            ; Caller teardown
CALLERT     LDR R0, R6, #0          ; Get return value into R0
            LDR R1, R5, #0          ; Get value of result into R1
            ADD R0, R0, R1          ; result += charCount(str + 1, key);
            STR R0, R5, #0          ; Store result back into R5
            ADD R6, R6, #3          ; Pop return value and parameters

            ; return result;
            ; Callee teardown
CALLEET     LDR R0, R5, #0          ; Load result into R0
            STR R0, R5, #3          ; Store result in space allocated for return value
            ADD R6, R5, #1          ; Pop locals
            LDR R5, R6, #0          ; Set dynamic link
            ADD R6, R6, #1          ; Pop dynamic link 
            LDR R7, R6, #0          ; Restore return address (R7)
            ADD R6, R6, #1          ; Move R6 to point at return value

            RET

            .END
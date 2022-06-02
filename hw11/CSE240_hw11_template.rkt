; Carlos Corral-Williams
;hw11

; Q1 (5 points)
; Enter your code here
;;prefix notation for solving basic math problems
(*(+ 9(- 2 5))3)
(+(*(- 3 5)(+(- 2  12)5))25)
(+ 1(* 4(-(- 22(+ 9 6))(/ 8 4))))
(*(- 10(* 4 2))(+ 4(/(+(* 6 6)(* 3 9))(+ 5 2))))
(+(* 2(+(-(/(+(*(+ 1 6)(+ 2 5))8)2)5)8))(+(/(+(* 4 5)(* 5 4))2)(* 4 5)))

; Q2 (5 points)
  ; Enter your code here
;using lambda function to construct a multiplying function
(define Multiply(lambda (q i)(* q i )))
(Multiply 10 40)


; Q3 (5 points)
; Enter your code here
(define (Exponent num power) ; two inputs
  (if (= power 0) 1 (* num (Exponent num (- power 1))))) ; if power to 0, then result is 1, otherwise continue to raise to power
(Exponent 3 3)

; Q4: Please enter test values 3 and 3. It should return 27. (5 points)
(display "Enter 3 3 as test case. It returns 27")
(newline)
(define (ReadForExponent)
; Enter your code here
(let((num (read))(power (read)))(Exponent num power))) ;let user input for num and power variables, then call the function for exponent
(ReadForExponent)

; Q5 (5 points)
(define (AddExponents
; Enter your code here
num1 power1 num2 power2) (+ (Exponent num1 power1) (Exponent num2 power2)));like exponent but takes 4 inputs and then computes the sum of both exponent instances
(AddExponents 2 5 3 2)

;Q6 (5 points)
(define (MultiplyLet q i)
; Enter your code here
(let ((z q)(v i))(Multiply q i))); let z's value and v's value to be the input for Multiply's q and i inputs, respectively
(MultiplyLet 10 3)

; Q7 (10 points)
(define (Letexpression)
; Enter your code here
(let ((three 3) (two 2) (five 5) (nine 9)) (*(+ nine (- two five))three))) ;assignment of each word and their integer they reference and then using established reference to compute math
(Letexpression)

; Q8: Enter values 1 2 3 4 5, and it should return 9. (10 points)
(display "Enter 1 2 3 4 5 and e, and it returns 9.")
(newline)
(define (accumulator oddsum next)	; recursive
; Enter your code here
;don't read non-integer values, and don't consider even user inputs 
(if (integer? next) (if (odd? next) ; if input is integer, assign to next, if odd? same thing
(accumulator (+ oddsum next) (read)) ; sum of oddnums up to this point
(accumulator oddsum(read))) ; sum of odd of nums read
oddsum)) ;; display total sum of odd numbers
(accumulator 0 0) 
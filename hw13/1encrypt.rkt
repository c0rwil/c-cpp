; Carlos Corral-Williams Tu Thu 4:30pm-5:45pm HW13

; 1.1 encryption using higher-order function map
(define encrypt
  (lambda(str)
    (list->string(map character-encrypt
                      (string->list str)))))
(define character-encrypt
  (lambda(character)
   (cond((or(char=? character #\A) (char=? character #\a))#\?)
        ((or (char=? character #\E) (char=? character #\e))#\!)
        ((or (char=? character #\O) (char=? character #\o))#\-)
        ((or (char=? character #\U) (char=? character #\u))#\*)
        ((or (char=? character #\I) (char=? character #\i))#\+)
        (else character))))
; It decrypts the string generated from your encryption function. The
; special characters (#?,  #!, #+, #-, and #*) in 1.1 must be decoded to their lowercase letters.
(define decrypt
  (lambda(str)
    (list->string (map character-decrypt
                       (string->list str)))))
(define character-decrypt
  (lambda(character)
    (cond((char=? character #\*)#\u)
         ((char=? character #\+)#\i)
         ((char=? character #\!)#\e)
         ((char=? character #\?)#\a)
         ((char=? character #\*)#\u)
         ((char=? character #\-)#\o)
         (else character))))

; TEST CASES
(encrypt "Zebra is a horse")
(decrypt (encrypt "Zebra is a horse"))
(encrypt "COMPUTER science")
(decrypt (encrypt "COMPUTER science"))
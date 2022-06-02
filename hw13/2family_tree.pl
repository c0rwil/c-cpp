/* Carlos Corral-Williams Tu Thurs 4pm:30-5:45pm HW13*/
/* Database for family tree. It consists of facts and rules. */
/* The section in the highlighted box above has been completed for you */

/* Facts */
male(abe).
male(rob).
male(jim).
male(ben).
male(bud).
male(kai).
male(lee).
male(roy).
male(tex).
male(mac).
female(joy).
female(ana).
female(mia).
female(mae).
female(amy).
female(pam).
female(kim).
female(zoe).
female(val).

/* Complete the facts given in the diagram above */
/* 2.1: finish adding the facts for remaining members on the family tree */
father_of(abe, ana). 
father_of(abe, rob).
father_of(abe, jim).
father_of(jim, mac).
father_of(jim, kim).
father_of(ben, bud).
father_of(ben, amy).
father_of(bud, zoe).
father_of(bud, val).
father_of(bud, tex).
father_of(bud, roy).
father_of(kai, lee).
father_of(kai, pam).
mother_of(joy, rob).
mother_of(joy, jim).
mother_of(joy, ana).
mother_of(mia, mac).
mother_of(mia, kim).
mother_of(mae, bud).
mother_of(mae, amy).
mother_of(ana, zoe).
mother_of(ana, val).
mother_of(ana, tex).
mother_of(ana, roy).
mother_of(amy, lee).
mother_of(amy, pam).


/* Rules */

is_male(X) :-
male(X);
father_of(X, _).

/* 2.2: Define a rule called is_female(X) */

is_female(X) :-
female(X);
mother_of(X, _).

/*2.3: grandmother_of(X, Z)*/

grandmother_of(X, Z) :-
mother_of(X, PARENT),
parent_of(PARENT, Z).

/* 2.4: sibling_of(X,Y) */
sibling_of(X, Y) :-
parent_of(PARENT,X),
parent_of(PARENT,Y),
Y \= X.

/* 2.5: parent_of(X,Y) */

parent_of(X,Y) :-
father_of(X,Y);
mother_of(X,Y).

/* 2.6: descendent_of(X,Y) */

descendent_of(X,Y) :-
parent_of(Y, X).

descendent_of(X,Y):-
parent_of(Y, Z),
descendent_of(X,Z).


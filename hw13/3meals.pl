/* Carlos Corral-Williams Tu Thurs 4pm:30-5:45pm HW13*/
/* FACTS: */

ingredient(greentea, green). /*3.1: create facts*/
ingredient(greentea, tea). /* ingredients of green tea */

ingredient(chips, salt). /*ingredients of chips*/
ingredient(chips, potato).

ingredient(lemonade, sugar). 
ingredient(lemonade, lemon).

ingredient(bread, flour).
ingredient(bread, egg).

entre(dinner, spagetti). /*entree specifications*/
entre(lunch, sandwich).

side(dinner, greentea). /* side specifications*/
side(dinner, bread).


side(lunch, lemonade).
side(lunch, chips).

/* RULES: */

/* 3.2: create rule meal(x,y) */
meal(X,Y) :- entre(X,Y); side(X,Y). /*meal specifications*/

/* 3.3: create shoppinglist(x,y) */
shoppinglist(X,Y) :- side(X,Z), ingredient(Z,Y). /*ingredients of everything included*/
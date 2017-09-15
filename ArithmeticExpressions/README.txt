Program reads in and evaluates arithmetic expressions. Types of expressions are lone integers, variables, unary operations, and binary operations. Expressions can be entered in reverse Polish notation, also known as postfix notation. Ex:

12 34 7 + * NEG done

The keyword "done" indicates the end of the expression. The above expression represents −(12 ∗ (34 + 7)).

Commands:
• set var num: sets the variable var to value num.
• unset var: reverts the variable var to the unassigned state. 
• print: prettyprints the expression.
• eval: evaluates the expression. This is only possible if all variables in the expression have values (even if the expression is x x -, which is known to be 0, the expression cannot be evaluated).

Example usage:
1 2 + 3 x - * ABS NEG done
-|((1 + 2) * (3 - x))| 
eval
x has no value.
set x 4 
print
-|((1 + 2) * (3 - 4))|
eval 
-3 
set x 3 
print
-|((1 + 2) * (3 - 3))|
eval 
0 
unset x 
print
-|((1 + 2) * (3 - x))|
eval 
x has no value.

# reverse-polish-notation-calculator

Takes numbers in "x y operator" format and ouputs the solution to "x operator y".

Handles negative numbers. Operators include: + (addition), - (subtraction), * (multiplication), / (division), % (remainder), A (last answer displayed, similar to "Ans" key), D (duplicates the top element of the stack), S (swaps the top two elements of the stack), C (clears the stack), $ (sine), E (returns value of e to the Xth power), ^ (returns X to the Yth power), = (followed by a-z to assign a value to a lowercase variable), a-z (retrives the assigned value based on the lowercase variable entered).

Uses a makefile to make running the program easier. Simply type "make run" to compile and run the multiple C source files.

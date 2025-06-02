# Lesson 3

## Global variables
They are defined outside functions, they are accessible to everyone and are dereferenciated only at the end of the program. They are useful for memorizing the state of the program.

## Static variables
They are usually defined inside functions. They work as global variables, memorizing status and mantaining it through various functions calls, but they are accessible only in the scope in which they are defined.

## Parameters passed by copy
In function calls, every parameter is passed by copy and not by reference (UNLESS WE ARE USING POINTERS, MORE ON THAT LATER)

## Implicit types promotion
(omitted)
BUT with signed int overflow we have an undefined behaviour (we could have proper overflow or other things...). With unsigned int, everything goes as planned (e.g. overflow 127 -> -128)



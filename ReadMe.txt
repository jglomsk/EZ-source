## Index:

Intro.........................Line 7
Keywords......................Line 14
Compiling.....................Line 25

## Introduction

Welcome to the EZ community! We want to personally thank you for using our program!
So, what is EZ?
EZ is a new programming language that teaches people who, frankly, know nothing about programming.
Our goal is to teach you the basics of programming and concepts of programming.
Shall we begin?

## Keywords

The word show will show you whatever comes after that word.
The word set will set a variable to whatever comes after the word to (e.g. set x to 42).
If you set a variable, you can then show it's value with show and then the variable name (e.g. show x).
If you want to set a variable to a formula, you can! Just do set var_name to formula (where var_name is the name of the variable and formula could be something like 42 + 90).
If you want to show a variable that was set to a formula, just show it!
Comments can be done with a simple semicolon (;).
Functions are supported in this version and can be made with a certain syntax (make func_name do stuff stuff stuff done).
The keyword make is used to begin a function. The keyword do starts the function. The keyword done ends it.
The keyword call allows you to call the function you made (e.g. make the function do whatever is inside).
The keyword if is a conditional statement. If your conditional is true, everything inside will execute.
The keyword else will execute if your conditional is false.
Showing a variable inside of a formula is not supported in this version of EZ (e.g. show x + 2).
Out of order formulas are not supported in this version of EZ (e.g. 2*3^5 is not supported, but (2*3)^5 and 2*(3^5) are supported).
Out of order formula setting to variables is not supported in this version of EZ.

## Compiling

In order to create and use your program, you're going to need (for alternative, go to line 47):
1: The interpreter that you should have downloaded.
    A: For Windows users: ez.exe
    B: For Mac/Linux users: ez.out
2: A command window.
    A: For Windows users: a command prompt window.
    B: For Mac/Linux users: a terminal window.
3: The full path to the ez interpreter.
    A: On Windows it should look like the following, but with your_name replaced with your username: C:\Users\your_name\Downloads\ez.exe
    B: On Mac/Linux it should look like: ~/Downloads/ez.out
4: A file with the .ez extension (e.g. main.ez).
    A: You'll also need the full path to said .ez file.
        I. You should also know that to edit the .ez file you simply right click the file, click open with, and click your favorite text editor (e.g. Notepad).
Now for the actual compiling.
Simply type the following into your command window: <interpreter_path> <ez_file_path>
Replace interpreter_path with the full path to the interpreter (see Compiling: 3AB).
Replace ez_file_path with the full path to your .ez file (see Compiling: 4A).
Boom! You just programmed in EZ!
Have lots of fun!
Alternative compiling method:
1: Click your ez file.
2: Drag it to your interpreter. On Windows it is ez.exe but on Mac/Linux it is ez.out.
3: Watch your code run.

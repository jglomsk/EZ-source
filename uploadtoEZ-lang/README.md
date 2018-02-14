# EZ-lang

## Introduction

Welcome to the EZ community! We want to personally thank you for using our program!
<br/>
So, what is EZ?
<br/>
EZ is a new programming language that teaches people who, frankly, know nothing about programming.
<br/>
Our goal is to teach you the basics of programming and concepts of programming.
<br/>
Shall we begin?
<br/>
First, download the .zip from the green "Clone or download" button, then extract the files to wherever you want.
<br/>
Make sure you remember where you put these files, as it will be important later on. In this documentation, we used the "Downloads" folder for example purposes.

## Keywords

The word show will show you whatever comes after that word.
<br/>
The word set will set a variable to whatever comes after the word to (e.g. `set x to 42`).
<br/>
If you set a variable, you can then show it's value with show and then the variable name (e.g. `show x`).
<br/>
If you want to set a variable to a formula, you can! Just do `set var_name to formula` (where `var_name` is the name of the variable and `formula` could be something like `42 + 90`).
<br/>
If you want to show a variable that was set to a formula, just show it!
<br/>
Comments can be done with a simple semicolon (`;`).
<br/>
Functions are supported in this version and can be made with a certain syntax (`make func_name do stuff stuff stuff done`).
<br/>
The keyword make is used to begin a function. The keyword do starts the function. The keyword done ends it.
<br/>
The keyword call allows you to call the function you made (e.g. make the function do whatever is inside).
<br/>
The keyword if is a conditional statement. If your conditional is true, everything inside will execute. The keyword done ends the statement.
<br/>
The keyword else will execute if your conditional is false. The keyword done ends the statement.
<br/>
The keyword while will execute whatever is inside while your conditional is true.
<br/>
Don't worry about incrementing or decrementing, we already took care of that for you.
<br/>
The keyword done means you're ready for your loop to be done and do it's thing.
<br/>
The keyword input inside a setting of a variable means you take input and set it to that variable (e.g. `set x to input`).
<br/>
Want a set of things? With EZ's new basket, it's EZr than ever.
<br/>
Simply set a variable to a basket (e.g. `set x to basket`).
<br/>
Then, push something into it (e.g. `push 82 into x`).
<br/>
Show off that basket with a show keyword (e.g. `show x`), or show off a single element (e.g. `show x[1]`).
<br/>
Elements in baskets start at 0, and go up by one (e.g. `x[0]` will equal the first thing you push into `x`, `x[1]` will be the second).
<br/>
You can now make classes. Check class.ez for examples.
<br/>
Classes are simply made just like functions, but they can hold other functions and variables inside.
<br/>
Parameters for functions are here!
<br/>
Simply make a function, then next to the function declaration type `wp param_name` (e.g. `make my_func do wp param`).
<br/>
This will allow you to execute a function with a specific variable. See basketeer.ez for examples.
<br/>
The keyword delete will delete a variable. See example.ez for more.
<br/>
Showing a variable inside of a formula is not supported in this version of EZ (e.g. `show x + 2`).
<br/>
One line if else statements are not supported in this version of EZ (e.g. `if x > 1 stuff done else stuff done`).
<br/>
Out of order formulas are not supported in this version of EZ (e.g. `2*3^5` is not supported, but `(2*3)^5` and `2*(3^5)` are supported).
<br/>
Out of order formula setting to variables is not supported in this version of EZ.
<br/>
Setting while loops to check for words is not supported in this version of EZ (e.g. `while x ! yes`).

## Running

In order to create and use your program, you're going to need:
<br/>
1. The interpreter that you should have downloaded.
	1. For Windows users: `ez.exe`
	2. For Linux users: `ez.out`
	3. For Mac users: `ez.mac`
2. A command window.
	1. For Windows users: a command prompt window.
	2. For Mac/Linux users: a terminal window.
3. The full path to the ez interpreter.
	1. On Windows it should look like the following, but with `your_name` replaced with your username: `C:\Users\your_name\Downloads\ez.exe`
	2. On Mac/Linux it should look like: `~/Downloads/ez.out`
		1. NOTE: On Mac/Linux, simply put a dot (.) in front of your interpreter path. (e.g. `./Downloads/ez.out <ez_file_path>`).
4. A file with the .ez extension (e.g. main.ez).
	1. You'll also need the full path to said .ez file.
		1. You should also know that to edit the .ez file you simply right click the file, click open with, and click your favorite text editor (e.g. Notepad).

Now for the actual running.
<br/>
Simply type the following into your command window: `<interpreter_path> <ez_file_path>`
<br/>
Replace `interpreter_path` with the full path to the interpreter (see Compiling: 3AB).
<br/>
Replace `ez_file_path` with the full path to your .ez file (see Compiling: 4A).
<br/>
Boom! You just programmed in EZ!
<br/>
Have lots of fun!
<br/>

Alternative interpreting method:
1. Click your ez file.
2. Drag it to your interpreter. On Windows it is `ez.exe` but on Mac/Linux it is `ez.mac` or `ez.out`, respectively.
3. Watch your code run.

Another alternative (FOR MAC/LINUX ONLY):
<br/>
1. Open a terminal (Mac: Command + Space, then search "Terminal"; Linux people should know how to do this).
2. Change to the directory you extracted the files to (should be like ~/Downloads/EZ-lang). Use the cd command to do this (e.g. `cd ~/Downloads/EZ-lang`) and then press Enter.
3. Type the following command then press Enter: `sudo ./install.out` or if you're on Mac: `sudo ./install.mac`
	1. WARNING!!! This command will ask for an admin password. If you are not an admin, simply do not use this method. Instead, use the original method or the first alternative.
4. Now you can change directory to wherever you want and simply type `ez <ez_file.ez>` replacing `<ez_file.ez>` with the name of your ez file, followed by the Enter key. Do not include the carets (<>) in the name.

Yet another alternative (FOR WINDOWS 10 USERS ONLY):
<br/>
1. Open the location of your ez file and the interpreter (e.g. Downloads).
2. Click the blue File button in the top left of the File Explorer window.
3. Click "Open Windows Powershell" while in the directory.
4. Type the following, replacing `your_file` with your ez file: `.\ez.exe .\your_file.ez`
## Known Bugs

1. You may have to change the permissions on the interpreter file.
	1. An ez fix (for Windows) is to right click the ez.exe file and click "Run as administrator". This may (or may not) cause a window to appear, saying the file was downloaded from an untrusted source. 
		1. If you downloaded this program from our GitHub (https://github.com/coderhelpfromtwitter/EZ-lang) then you are safe. Simply click "Advanced options" or "More Info" then click "Run Anyway."
1. If you type the full path to your ez FILE (not to be confused with the interpreter) and include a source file via the "with" keyword, you may run into some issues running your ez file.
	1. We suggest putting all your ez files that you want to use in the same place, then running one ez file at a time.
		1. If you plan on not taking our suggestion, good luck. We are currently working on a fix and this known bug's documentation will be deleted once it is fixed.

## Updates

We will soon be releasing an online version of the EZ language. For now, you can go to the maintained (but minimal) website for running this program.
<br/>
It can be found at: https://ez-lang.codeanyapp.com/

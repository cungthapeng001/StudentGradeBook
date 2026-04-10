# Student GradeBook System - Viva Questions

Here are some common viva questions you might be asked regarding this project, divided by topics, along with pointers for how to answer them:

## 1. Modular Programming & Header Files
**Q: I see you have multiple `.c` files and `.h` files. Why did you separate your project this way instead of keeping everything in `main.c`?**
*Answer:* Splitting the code into separate modules (like `insert.c`, `searchByRoll.c`, etc.) makes the program modular, easier to debug, and much more readable. If I want to change how searching works, I only have to look at one small file. The `.h` (header) files act as a bridge that tells the compiler about the functions and structures (like our `Student` struct) available across these different files.

**Q: What is the `#ifndef` and `#define` mapping at the top of your header files (e.g., `#ifndef STUDENT_H`)?**
*Answer:* Those are Include Guards. They prevent a header file from being included multiple times in the same compilation process, which would cause "redefinition" errors by the compiler.

## 2. Structures (Structs)
**Q: You used a `struct` called `Student`. What is the advantage of using a `struct` rather than parallel arrays (one array for names, one for rolls, etc.)?**
*Answer:* A `struct` groups related data items of potentially different types under a singular name. Instead of updating 5 disconnected arrays whenever I delete or swap a student, I can move the entire compiled `Student` entity in one simple sweep (`studentList[i] = studentList[i+1]`). It groups data logically the way humans think about an object.

**Q: How do you access a specific property within a struct?**
*Answer:* We use the dot operator (`.`). For example, `studentList[i].roll` accesses the roll number of the student at index `i`.

## 3. Pointers and Pass-by-Reference
**Q: In your functions, like `addStudentData(int *students, ...)`, why do you pass `students` as a pointer using the `*` symbol?**
*Answer:* Because C natively passes arguments by "value" (it creates a copy). If I just pass the integer `students` and increment it when adding a new person, the original variable in `main.c` wouldn't change. Passing the memory address via a pointer (`*students`) allows the `insert` module to modify the core registry count residing over in `main.c`.

## 4. File Handling
**Q: How does your system remember the data after it closes?**
*Answer:* It relies on file handling. We export the properties to a file named `database.dat`. 

**Q: What do the `"wb"`, `"rb"`, and `"a"` flags stand for inside your `fopen()` commands?**
*Answer:* 
- `"wb"` specifies "Write Binary". It opens the dat file for writing raw binary data and erases the old file. 
- `"rb"` is "Read Binary", acting to cleanly pull raw structs.
- `"a"` stands for "Append" (used in `activity_log.dat`). It opens a file and writes new text at the very bottom without destroying the preexisting log history.

**Q: Why use `fwrite()` and `fread()` instead of `fprintf()` and `fscanf()` for the database?**
*Answer:* Because we are saving high-level `structs` directly. Rather than formatting names and integers block by block as strings into a readable text document, binary block writing instantly stamps the machine's memory directly to disk layout, making scaling drastically faster and more accurate.

## 5. System Compilation
**Q: Can you explain your `gcc` command? Why do we list all the `.c` files but ignore the `.h` files?**
*Answer:* `gcc` takes all of our distinct "source code" files (`.c` files) and compiles them simultaneously linking them into one `.exe` executable. We do not list `.h` files because the preprocessor automatically injects the content of included `.h` files directly into `.c` spaces wherever it spots an `#include` tag before compilation begins.

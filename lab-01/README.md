# CS 241 Data Organization using C

# Lab 1: Introduction to C, ASCII Art, and the Linux Command Line Environment

## 1. Brief Introduction to Command Line Linux

This lab is designed for you to have a chance to familiarize yourself with the computing environment we will be using this semester, and in a number of upper level CS classes. Before this class, you will need to have a CS server account. 

### 1.1 Log in to CS lab Linux computer
Use SSH to connect to a CS machine.

### 1.2 Running some basic Linux Commands
Hopefully now you are logged in, and on your screen you have and empty window that has a text line in it that looks something like this:

>ls -F
appends a “*” to the end of every executable file, a “/” to the end of every folder, an “@” to end of every symbolic link, and a few other suffixes for other special file types.

>ls -l
creates a more verbose listing of the files and folders in the directory that includes permissions, size, date modified, the user name of the owner, and some other information.

>ls -a
includes hidden files: that is files with names whose first character is “.”. These generally include various configuration files. Some of these files are automatically executed during the login process. Some are executed when a particular application starts. One file of particular note is the .bashrc file. This file is a plain text, batch file that runs automatically run during login. Unless you know what you are doing, you should not change anything in this file; however, it is generally safe to add new commands to the end of the file. For example, many people append the Linux command “alias ls=’ls -F’” to the end of their .bashrc. This creates an alias for ls so that whenever “ls” is entered as a command, Linux will replace it with “ls -F”.

>ls -laF
applies all three of the above effects.
Find out more about ls by reading the manual pages. The command “man ls” at the command prompt will display the manual pages (often called man pages).

>cp existingFileName newFileName - Copies file

>mv existingFileName newFileName - renames/moves a file

>rm fileName - removes(deletes) the file

### 1.3 Creating Directories

Create a new folder (called directory in Linux) with the mkdir command. For example, if you want to create a folder called foo101 enter the command: mkdir foo101.

### 1.4 Navigating Directories
Next up, we’ll try to descend into the newly created directory. This can be done by using the cd (change directory) command: cd foo101.
Now that the active command location has entered the newly created directory, enter the ls -aF command, and you will see that the directory is empty except for two directories: “./” and “../”. The first of these is a pointer to the current directory and the second is a pointer to the directory one level up. Thus, “cd ..” will return the active command location back to your home directory. Additionally, no matter where you are in a directory structure, you can always return to your home directory with the command “cd  ”.


## Problem Specification
Use an SSH application to connect to moons.cs.unm.edu, trucks.cs.unm.edu, or trusty.cs.unm.edu with your CS account.

Create a new working directory called cs241, and within that directory create another directory called lab-01.
Use the Linux shell chmod command to ensure that only the owner has read, write, and execute permissions for this new lab directory.
Within this directory, you are to create a C program, stored in the file asciiArt.c.
Your asciiArt.c must use the printf function to display to the standard output stream an ASCII art image that fits within 60x24 columns and rows. It is ok to be smaller than that size. Your image must be a stylized version of your first or last name. Each “letter” must be at least 3x3 characters: printf("Marie\n") would NOT get credit as an ASCII art image of my name.4
The first five lines of your asciiArt.c must be of the form:
```
/*************************************************/  
/* YourFirstName YourLastName                    */  
/* Date                                          */  
/* CS-241 Section #                              */  
/*************************************************/
```
Use the Linux shell chmod command to ensure that only the owner has read and write permissions for your asciiArt.c.
Compile the program with /usr/bin/gcc.5
Compile and run your modified program with the output redirected from the shell to a text file called yourfirstname-yourlastname.txt. This is done using a shell redirection “>” command:

```./a.out > yourfirstname-yourlastname.txt```

From the lab directory you created in step 1, run the Linux command:

```pwd > out1.txt```

This will create a file that shows the directory path you created. It must be the correct directory path on *.cs.unm.edu of your CS account home directory with the directory created in step 1.

From the lab directory you created in step 1, run the Linux command:

```ls -a -l > out2.txt```

This will create a file containing a listing of the current directory (.), the parent directory (..), your asciiArt.c file, the executable file a.out, and whatever other files you have in the directory. The out2.txt file you created must include the permissions, owner, group, size and date of each file. The permissions of the current directory and your C program must only be read/write (and execute for the directory and program) for the owner.
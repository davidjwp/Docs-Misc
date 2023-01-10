# **Shell_01**
### COMMAND_LINES

*collection of information on shell utilities*
*for further more detailed information it is better to use the manual*


**cd** 
*current directory: used to change the current directory*
    
    $cd directory/subdir
    $cd ../../
**pwd**
*Print Working Directory: outputs the path to current directory*

    $pwd
**ls**
*list directory content: list information about the files in the directory(current by default)*

    $ls
    $ls directory/
**man**
*manual: an interface to the system reference manuals*

    $man cd
    $man pwd
**cat**
*concatenate files and print on the standard output*

    $cat file.c

**tar**	
*an archiving utility*
    
    $tar -cf archname file.c
-   **-c** create
-   **-f** file

**ln** 
*link name: make link between files*

    $ln file linkname
    $ln -s file linkname
-   **-s** symbolic link

**chmod** 
*change mode: change file mode bits(file permissions)*

    $chmod a+rwx file
    $chmod ug-r file2
-   **u** user
-   **g** group
-   **o** other
-   **a** all
-   **r** read
-   **w** write
-   **x** execute

**touch** 
*change file timestamps (can also be used to create and write in file)*

-t YYYYMMDDHHMM.SS to change file modification time 

$tr 'char1' 'char2' command line translate or delete characters of char1 to char2 

$git status			shows which files are commited and the general status
				which ones are tracked and which ones aren't
$git add			to add to track
$git commit -m			to tell git you are about to push with message 
$git push			to push to directory
$git -ignore			to ignore certain files 
$git clone (git repo address)	to clone a git repo in the directory 

$git ls-files -o -i --exclusion-standard	-o goes for others and -i for ignored 

$id [OPTIONS] ... [USER] print real and effective user and group IDs/ id -G -n [USER] -G for all group IDs -n for name instead of number 

$ls -p -m -t /-p append/ to directory /-m fill width with comma /-t sort by modification time

$sed command for alot of things can be used to modify a string in a file 
$sed 's/text1/text2/OPTIONS' [FILE]

$find . -type f -name '*.sh' -exec basename {} .sh \; #-exec is for executing command so -exec [COMMAND] {} basename removes the directory and suffix from this name .sf# 

REALLY USEFUL /'anything' to search for anything 

for magic file:
https://www.mkssoftware.com/docs/man4/magic.4.asp

$gcc (file)	compile your program
$gcc -I (file)	adds include directory of header files

FAUT PENSER A LOCK TA SESSION
yes "LOCK TA SESSION <3"

LLDB--------INFO:

lldb on the binary, then b "breakpoint location" ex:

$lldb a.out
$b main
$run
$gui //will give you a graphical interface and make it much easier to comprehend

Shell_01:::::::::
GENERAL_INFO:::::
:::::::::::::::::

virtual studios does not add a line which results in one less byte.


file perimssions (XXX) owner(XXX) group (XXX) other (X) allow execute to remove permission use chmod u or g for user or group, - whatever you want to take out 

remnants from Shell_02

shell01
ctrl a to go to the head of the line ctrl e to go to last line 

rmdir --ignore-fail-on-non-empty 

env command is a real program that allows you to see the shell environment 
$ lets you to tell shell you want to use the name as a variable
* placeholder to say all name types all .txt *.txt


id #print real and effective user and group ID# -G #group# -n #name# $FT_USER | tr #translate or delete characters# ' ' # '[ESPACE]'# ',' #'[COMMA]'#
prints the groups id while replacing spaces with a comma

find . -type f -name "*.sh" -exec #execute basename which strips the directory and suffix from filenames# basename {} .sh \;
finds and outputs every file with .sh while executing a command to take the suffix from filenames 

basename NAME [SUFFIX]

find . -type f,d #find type file,directory# | wc #print newline, word, and byte for each file# -l #--lines print the newline counts#
finds files in the current and sub-directory and prints the number of regular files and directories

ifconfig #allows configuration of the kernel between network interfaces#| awk #script language to manipulate data#'/ether/{print $2}' #print from line $2#
awk options 'selection_criteria {action}' input-file > output-file 

ar rc [LIBNAME] [*.o] ranlib

creates a library with all the functions so you can simply reuse the library when compiling, use ranlib
to create an index of the functions in your library so it can run faster, it allows the compiler to find where the function being used 
is.

ar dv [LIB_A] [FUNCT_O]


used to remove a particular function from the library, LIB_A is the archive file and FUNCT_O is the object file of the function you whish to remove.

norminette -R CheckForbiddenSourceHeader

fdisk

lsblk

blkid

# Exercise 01: print_groups
Write a command line that will display the list of groups for which the login, contained in the environment variable FT_USER, is a member. Separated by commas without spaces.\
Example:\
for FT_USER=nours, the result is god,root,admin,master,nours,bocal

%> ./print_groups.sh\
god,root,admin,master,nours,bocal

Example:\
for FT_USER=daemon, the result is daemon,bin

%> ./print_groups.sh\
daemon,bin

## Used functions:
* groups (man groups) https://man7.org/linux/man-pages/man1/groups.1.html
* tr (man tr) https://man7.org/linux/man-pages/man1/tr.1.html

(create file with vim type:) vim print_groups.sh\
(type:)\
#!/bin/sh\
groups $FT_USER | tr ' ' ',' | tr -d '\n'\
(save and close)

# Exercise 02: find_sh
Write a command line that searches for all file names that end with “.sh” (without quotation marks) in the current directory and all its sub-directories. It should display only the file names without the .sh.\
Example of the output:

%> ./find_sh.sh | cat -e\
find_sh\
file1\
file2\
file3

## Used functions: 
* find (man find) https://man7.org/linux/man-pages/man1/find.1.html
* tr (man tr) https://man7.org/linux/man-pages/man1/tr.1.html
* sed (man sed) https://man7.org/linux/man-pages/man1/sed.1.html

(create file with vim type:) vim find_sh.sh\
(type:)\
#!/bin/sh\
find . -name "*.sh" | sed 's:.*/::' | sed 's/\.[^.]*$//'\
(save and close)


# Exercise 03: count_files
Write a command line that counts and displays the number of regular files and directories in the current directory and all its sub-directories. It should include “.“, the starting directory.\
Example of the output:

%> ./count_files.sh | cat -e\
42

## Used functions
* find (man find) https://man7.org/linux/man-pages/man1/find.1.html
* tr (man tr) https://man7.org/linux/man-pages/man1/tr.1.html
* wc (man wc) https://man7.org/linux/man-pages/man1/wc.1.html

(create file with vim type:) vim count_files.sh\
(type:)\
find . -type f -or -type d | wc -l | tr -d " "\
(save and close)

# Exercise 04: MAC
Write a command line that displays your machine’s MAC addresses. Each address must be followed by a line break.

## Used functions 
* ifconfig (man ifconfig) https://man7.org/linux/man-pages/man8/ifconfig.8.html
* grep (man grep) https://man7.org/linux/man-pages/man1/grep.1.html
  
(create file with vim type:) vim MAC.sh\
(type:)\
ifconfig -a | grep -o -E '([0-9a-fA-F]{2}:){5}[0-9a-fA-F]{2}'\
(save and close)

# Exercise 05: Can you create it ?
Create a file containing only “42“, and NOTHING else.\
Its name will be:

"\?$*'MaRViN'*$?\"\

Example:\
%> ls -lRa *MaRV* | cat -e\
-rw---xr-- 1 75355 32015 2 Oct 2 12:21 "\?$*'MaRViN'*$?\"

## Used functions:
* chmod (man chmod) https://man7.org/linux/man-pages/man2/chmod.2.html
* touch (man touch) https://man7.org/linux/man-pages/man1/touch.1.html

(create file type:) touch \"\\\?\$\*\'MaRViN\'\*\$\?\\\"\
(edit file with preferred editor and type:) 42\
(change permission type:) chmod u-x, u+rw, g-rw, g+x, o-wx, o+r \"\\\?\$\*\'MaRViN\'\*\$\?\\\"\
(change time type:) touch -amt 202310021221.00 \"\\\?\$\*\'MaRViN\'\*\$\?\\\"\
|Author comment: If you dont use the cat -e command you wont get the desired output even with the correct file name.|

# Exercise 06: Skip
Write a command line that displays one line out of two for the command ls -l, starting from the first line.

## Used functions:
* ls (man ls) https://man7.org/linux/man-pages/man1/ls.1.html
* awk (man awk) https://man7.org/linux/man-pages/man1/awk.1p.html

(create file with vim type:) vim skip.sh\
(type:)\
#!/bin/sh\
ls -l | awk "NR % 2 != 0"\
(save and close)

# Exercise 07 : r_dwssap
Write a command line that displays the output of a cat /etc/passwd command, removing comments, every other line starting from the second line, reversing each login, sorted in reverse alphabetical order, and keeping only logins between FT_LINE1 and FT_LINE2 included, and they must separated by ", " (without quotation marks), and the output must end with a ".".

Example:\
Between lines 7 and 15, the result should be something like this :\
$> ./r_dwssap.sh\
sstq_, sorebrek_brk_, soibten_, sergtsop_, scodved_, rlaxcm_, rgmecived_, revreswodniw_, revressta_\
.$>

## Used functions
* cat (man cat) https://man7.org/linux/man-pages/man1/cat.1.html
* sed (man sed) https://man7.org/linux/man-pages/man1/sed.1.html
* awk (man awk) https://man7.org/linux/man-pages/man1/awk.1p.html
* cut (man cut) https://man7.org/linux/man-pages/man1/cut.1.html
* rev (man rev) https://man7.org/linux/man-pages/man1/rev.1.html
* sort (man sort) https://man7.org/linux/man-pages/man1/sort.1.html

(create file with vim type:) vim r_dwssap.sh\
(type:)\
#!/bin/sh\
cat /etc/passwd | sed '/^#/d' | awk 'NR % 2 == 0' | cut -d ':' -f 1 | rev | sort -r | sed -n "${FT_LINE1}${FT_LINE2}p" | sed 's/,$/./' | sed ':a;N;$!ba;s/\n/, /g'\
(save and close)

# Exercise 08 : add_chelou
Write a command line that takes numbers from variables FT_NBR1, in ’\"?! base, and FT_NBR2, in mrdoc base, and displays the sum of both in gtaio luSnemf base.

Example 1:\
FT_NBR1=\'?"\"'\\
FT_NBR2=rcrdmddd

The sum is :\
Salut

Example 2 :\
FT_NBR1=\"\"!\"\"!\"\"!\"\"!\"\"!\"\"\
FT_NBR2=dcrcmcmooododmrrrmorcmcrmomo

The sum is :\
Segmentation fault

## Used functions
* echo (man echo) https://man7.org/linux/man-pages/man1/echo.1.html
* sed (man sed) https://man7.org/linux/man-pages/man1/sed.1.html
* bc (man bc) https://man7.org/linux/man-pages/man1/bc.1p.html
* tr (man tr) https://man7.org/linux/man-pages/man1/tr.1.html

(create file with vim type:) vim add_chelou.sh\
(type:)\
#concatenating both variables\
get_initial_values=$(echo "$FT_NBR1 + $FT_NBR2")\
#replacing FT_NBR1 values\
replace_nbr1=$(echo "$get_initial_values" | sed -e "s/'/0/g" -e 's/\\/1/g' -e 's/\"/2/g' -e 's/\?/3/g' -e 's/\!/4/g')\
#replacing FT_NBR2 values\
replace_nbr2=$(echo "$replace_nbr1" | sed -e 's/m/0/g' -e 's/r/1/g' -e 's/d/2/g' -e 's/o/3/g' -e 's/c/4/g')\
#setting input and output base values\
set_bc_values="ibase=5; obase=23; $replace_nbr2"\
#calculating result\
calculate_value=$(echo "$set_bc_values" | bc)\
#converting result into text\
convert_result=$(echo "$calculate_value" | tr '0123456789ABC' 'gtaio luSnemf')\
#printing final result\
echo "$convert_result"\
(save and close)

|Author comment: The only way to get the correct output was to replace obase=13 to obase=23 (Lexical Conventions in bc: point 9.)|


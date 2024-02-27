# Exercise 00: Z
Create a file called z that returns “Z”, followed by a new line, whenever the command cat is used on it.

PowerShell\
%> cat z\
Z\
%>

## Used functions: 
* echo (man echo) https://man7.org/linux/man-pages/man1/echo.1.html

(create and write type:) echo Z > z

# Exercise 01 : testShell00
Create a file called testShell00 in your submission directory.
Figure out a way for the output to look like this (except for the “total 1” line):

PowerShell\
%> ls -l\
total 1\
-r--r-xr-x 1 XX XX 40 Jun 1 23:42 testShell00\
%>

Once you’ve achieved the previous steps, execute the following command to create the file to be submitted: tar -cf testShell00.tar testShell00.

## Used functions: 
* truncate (man truncate) https://man7.org/linux/man-pages/man2/truncate.2.html
* chmod (man chmod) https://man7.org/linux/man-pages/man2/chmod.2.html
* touch (man touch) https://man7.org/linux/man-pages/man1/touch.1.html

(change size type:) truncate -s40 testShell00\
(change permission type:) chmod u-wx,u+r,g-w,g+rx,o-w,o+rx testShell00\
(change time type:) touch -amt 202306012342.00 testShell00

# Exercise 02 : Oh yeah, mooore…
Create the following files and directories. Do what’s necessary so that when you use the ls -l command in your directory, the output will look like this:

PowerShell\
%> ls -l\
total XX\
drwx--xr-x 2 XX XX XX Jun 1 20:47 test0\
-rwx--xr-- 1 XX XX 4  Jun 1 21:46 test1\
dr-x---r-- 2 XX XX XX Jun 1 22:45 test2\
-r-----r-- 2 XX XX 1  Jun 1 23:44 test3\
-rw-r----x 1 XX XX 2  Jun 1 23:43 test4\
-r-----r-- 2 XX XX 1  Jun 1 23:44 test5\
lrwxrwxrwx 1 XX XX 5  Jun 1 22:20 test6 -> test0\
%>\
Once you’ve done that, run tar -cf exo2.tar * to create the file to be submitted.

## Used functions
* mkdir (man mkdir) https://man7.org/linux/man-pages/man1/mkdir.1.html
* ln (man ln) https://man7.org/linux/man-pages/man1/ln.1.html
* truncate (man truncate) https://man7.org/linux/man-pages/man2/truncate.2.html
* chmod (man chmod) https://man7.org/linux/man-pages/man2/chmod.2.html
* touch (man touch) https://man7.org/linux/man-pages/man1/touch.1.html


(create directory type:) mkdir test0\
(change permission type:) chmod u+rwx,g-rw,g+x,o-w,o+rx test0\
(change time type:) touch -amt 202306012047.00 test0

(create and write file type:) echo "Hi " > test1\
(change permission type:) chmod u+rwx,g-rw,g+x,o-wx,o+r test1\
(change time type:) touch -amt 202306012146.00 test1

(create directory type:) mkdir test2\
(change permission type:) chmod u-w,u+rx,g-rwx,o-wx,o+r test2\
(change time type:) touch -amt 202306012245.00 test2

(create file type:) echo > test3\
(change permission type:) chmod u-wx,u+r,g-rwx,o-wx,o+r test3\
(change time type:) touch -amt 202306012344.00 test3

(create file type:) echo A > test4\
(change permission type:) chmod u-x,u+rw,g-wx,g+r,o-rw,o+x test4\
(change time type:) touch -amt 202306012343.00 test4

(create link type:) ln test3 test5

(create link type:) ln -s test0 test6\
(change permission type:) chmod -h u+rwx,g+rwx,o+rwx test6\
(change time type:) touch -hamt 202306012220.00 test6

# Exercise 03 : SSH me!

Create your own SSH key. Once it is done:\
Add your public key to your repository, in a file name id_rsa_pub\
Update your ssh key on the intranet. This will allow you to push the repository to our git server.

## Used functions 
* cat (man cat) https://man7.org/linux/man-pages/man1/cat.1.html

(display Key type:) cat ~/.ssh/id_rsa.pub\
(create file and edit - CAREFUL WITH THE FILE NAME - type:) vim id_rsa_pub\
(copy your public key,save and close)

# Exercise 04 : midLS
In a midLS file, place the command line that will list all files and directories in your current directory (except for hidden files or any file that starts by a dot – yes, that includes double-dots), separated by a comma and a space, by order of modification date. Make sure the directory’s names are followed by a slash character.

## Used functions:
* ls (man ls) https://man7.org/linux/man-pages/man1/ls.1.html

(create file with vim type:) vim midLS\
(list files type:) ls -pmt\
(save and close)

# Exercise 05 : GiT commit
Create a shell script that displays the ids of the last 5 commits of your git repository.

## Used functions:
* git (man git) https://man7.org/linux/man-pages/man1/git.1.html
* git-log (man git-log) https://man7.org/linux/man-pages/man1/git-log.1.html

(create file with vim type:) vim git_commit.sh\
(list commits type:) git log --format=%H -n5\
(save and close)

# Exercise 06: gitignore
In this exercise, you will write a short shell script that lists all the existing files ignored by your GiT repository. Example:

PowerShell\
%> bash git_ignore.sh | cat -e\
.DS_Store\
mywork.c~\
%>\
To test your script, we will use our own environment.

## Used functions
* git (man git) https://man7.org/linux/man-pages/man1/git.1.html
* git-ls-files (man git-ls-files) https://man7.org/linux/man-pages/man1/git-ls-files.1.html

(create file with vim type:) vim git_ignore.sh\
(list commits type:) git ls-files -o -i --exclude-standard\
(save and close)

# Exercise 07: diff
Create a file b, so that:

PowerShell\
%> cat -e a\
STARWARS\
Episode IV, A NEW HOPE It is a period of civil war.

Rebel spaceships, striking from a hidden base, have won their first victory against the evil\
Galactic Empire.\
During the battle, Rebel spies managed to steal secret plans to the Empire's ultimate weapon, the\
DEATH STAR,\
an armored space station with enough power to destroy an entire planet.

Pursued by the Empire's sinister agents, Princess Leia races home aboard her starship, custodian of\
the stolen plans that can save her people and restore freedom to the galaxy...

PowerShell\
%> diff a b > sw.diff

## Used functions
* git (man git) https://man7.org/linux/man-pages/man1/git.1.html
* patch (man patch) https://man7.org/linux/man-pages/man1/patch.1.html

(extract the resource files)
(create b file type:) patch a -o b < sw.diff

# Exercise 08: clean
In a file called clean place the command line that will search for all files – in the current directory as well as in its sub-directories – with a name ending by ~, or a name that start and end by #.\
The command line will show and erase all files found.\
Only one command is allowed: no ; or && or other shenanigans.

## Used functions
* find (man find) https://man7.org/linux/man-pages/man1/find.1.html

(create file with vim type:) vim clean\
(type:) find . -type f \( -name "*~" -o -name "#*#" \) -print -delete\
(save and close)\
|Author comment: the flag iname should work but when i used it it wasnt accepted|

# Exercise 09: Illusions, not tricks, Michael…
Create a magic file called ft_magic that will be formatted appropriately to detect files of 42 file type, built with a 42 string at the 42nd byte.

## Used functions
* None
  
(create file with vim type:) vim ft_magic\
(type:) 41	string	42	42 file\
(save and exit)\
|Author comment: Thats 41 then Tab then string, space, Tab 42 file recommend reading https://0xpius.hashnode.dev/a-quick-guide-to-magic-files|







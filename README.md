# Contiguous-Memory-Allocation-of-files-into-disk
Simulation program for the contiguous memory allocation of files into disk
pproach:
 Contiguous Allocation of memory in disk states that the 
every part of the file should be allocated in the 
contiguous manner in the disk i.e. if a file is storing in 
the disk then it needs to be present in the disk in 
contiguous blocks, not in scattered blocks.
 I’ve used Array data structure as it stores data items in 
contiguous manner.
 In the simulation code, I’ve used four functions which 
helps in initializing a disk, allocating file to a disk, 
deleting file from disk and displaying the blocks of disk 
whether the block in a disk is empty or allocated with 
files.
 I’ve used switch case statements in the code so that it 
would be easy to do contiguous memory allocation.
 The disk size is fixed i.e. in the code we have defined the 
disk size earlier.
 A structure is defined which contains the character array 
to represent file name with maximum limit of 20 
characters, two integer variables, one represents the 
starting block of the disk we want to fit the file in and 
the other represents the ending block of the disk we 
want to fit the file in.
 The user need to mention the initial block and ending 
block of the disk that he/she wants to fit the file in.
 If the file size is greater than the remaining disk size, the 
file won’t be allocated to the disk.
 ‘X’ represents that the block is allocated to a particular 
part of a file/ whole file and ‘.’ Represents that the 
particular block is empty and no part of the file or full 
file is allocated to it.
 When we want to delete any file from the disk, we need 
to specify the serial number of file i.e. the order of file in 
the file list. If it exists in the disk, it will delete the file 
from disk and empty the space and display message that 
the file got deleted from the disk. If not, it will display 
that the file doesn’t exist in the file.

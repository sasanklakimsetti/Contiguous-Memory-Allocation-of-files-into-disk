//CA3
//NAME: SAI SASANK LAKIMSETTI
//REGISTRATION NUMBER: 12209302
//ROLL NUMBER: 68
//SECTION: K22SR
//QUESTION: 5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DISK_SIZE 1000
#define MAX_FILES 50
typedef struct File
{
    char filename[20];
    int start;
    int end;
} File;
int disk[DISK_SIZE];
int num_of_files = 0; //initially setting it to zero. later increase and decrease according to the task performed
File files[MAX_FILES]; // an array used to store files that were allocated in 

//Function to initialize disk
void initialiseDisk() 
{
    for (int i = 0; i < DISK_SIZE; i++) 
    {
        disk[i] = -1; //block is empty
    }
}
//Function to allocate files in the disk
int allocateFile(File file) 
{
    int file_size = file.end - file.start + 1;
    int remaining_space = 0;
    for (int i = 0; i < DISK_SIZE; i++) 
    {
        if (disk[i] == -1) 
        {
            remaining_space++;
        }
    }
    if (file_size > remaining_space) 
    {
        printf("ERROR!: File size greater than remaining disk space. No allocation of the file will done.\n");
        return 0;
    }

    for (int block = file.start; block <= file.end; block++) 
    {
        if (disk[block] != -1) 
        {
            printf("ERROR!: Disk Space not available.\n");
            return 0; // file allocation error
        }
        else 
        {
            disk[block] = file_size; //allocation of disk space to the file
        }
    }
    num_of_files++;
    files[num_of_files - 1] = file; // file added to the list
    return 1; // successful allocation of disk space to the file
}
//Function to delete a file from disk
void deleteFile(File fileToDelete) 
{
    char deletedFilename[20];
    for (int block = fileToDelete.start; block <= fileToDelete.end; block++) 
    {
        disk[block] = -1;  //deallocation of disk space where the deleted file is situated earlier
    }
    // Find the corresponding filename in the list of files
    for (int i = 0; i < num_of_files; i++) 
    {
        if (files[i].start == fileToDelete.start && files[i].end == fileToDelete.end) 
        {
            strcpy(deletedFilename, files[i].filename); //copying the deleted filename from original list
            // Remove the file from the list of files
            if (i != num_of_files - 1) 
            {
                files[i] = files[num_of_files - 1];
            }
            break;
        }
    }
    num_of_files--;  //decrease value of number of files in the list
    printf("File '%s' successfully deleted.\n", deletedFilename);
}
//Function to display disk status whether disk is allocated or empty
void displayDisk() 
{
    printf("Disk Status:\n");
    for (int i = 0; i < DISK_SIZE; i++) 
    {
        if (disk[i] == -1) 
        {
            printf(". "); // Block is empty
        }
        else 
        {
            printf("X "); // Block is allocated to any file
        }
        //no error message after allocation of files less than the maximum number of files
        if ((i + 1) % 20 == 0) 
        {
            printf("\n");
        }
    }
}

int main() 
{
    initialiseDisk();  //Initializing disk with some units of space  (1000 - as defined earlier)
    int choice;
    while (1) 
    {
        printf("\n1. Allocate a file\n2. Delete a file\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1: 
            {
                if (num_of_files >= MAX_FILES) 
                {
                    printf("Error: Maximum number of files reached.\n");
                }
                else 
                {
                    File file;
                    printf("Enter filename: ");
                    scanf("%s", file.filename);
                    printf("Enter starting block of file: ");
                    scanf("%d", &file.start);
                    printf("Enter ending block of file: ");
                    scanf("%d", &file.end);
                    if (allocateFile(file)) 
                    {
                        printf("Space for File '%s' allocated successfully\n", file.filename);
                    } 
                    else 
                    {
                        printf("Space not available for File '%s'\n", file.filename);
                    }
                }
                break;
            }

            case 2: 
            {
                if (num_of_files > 0) 
                {
                    int deleteNum;
                    printf("Enter the S.No. of file to delete: ");
                    scanf("%d", &deleteNum);
                    if (deleteNum >= 1 && deleteNum <= num_of_files) 
                    {
                        File fileToDelete = files[deleteNum - 1];
                        deleteFile(fileToDelete);
                    } 
                    else 
                    {
                        printf("Invalid file number.\n");
                    }
                } 
                else 
                {
                    printf("No files to delete.\n");
                }
                break;
            }

            case 3:
                displayDisk();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid option.\n");
                break;
        }
    }
    return 0;
}
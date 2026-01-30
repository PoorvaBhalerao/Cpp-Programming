//CVFS-9

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                  Header File Inlclusion
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
//#include<unistd.h>
#include<stdbool.h>
#include<string.h>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                  User defined Macros
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Maximum file size that we allow in the project
#define MAXFILESIZE 50

#define MAXOPENFILES 20

#define MAXINODE 5

#define READ 1
#define WRITE 2
#define EXECUTE 4

#define START 0
#define CURENT 1
#define END 2

#define EXECUTE_SUCCESS 0

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                  User defined Structures
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Structure Name:         Boot Block
//  Descrription:           Hold the inforrmation to boot the OS.             
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct BootBlock
{
    char Informmation[100];
};


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Sructure Name:          Super Block
//  Descrription:           Hold the inforrmation about the file system.               
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


struct Superblock
{
    int TotalInodes;
    int FreeInodes;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Sructure Name:      Inode
//  Descrription:       Hold the inforrmation about file.                    
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
struct Inode
{
    char FileName[20];
    int InodeNumber;
    int FileSize;
    int ActualFileSize;
    int ReferenceCount;
    int Permission;
    char *Buffer;
    struct Inode *next;

};


typedef struct Inode INODE;
typedef struct Inode* PINODE;
typedef struct Inode** PPINODE;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Sructure Name:      Fileable
//  Descrription:       Hold the inforrmation about opened file.                    
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct FileTable
{
    int ReadOffset;
    int WriteOffset;
    int Mode;
    PINODE ptrinode;
};

typedef FileTable FILETABLE;
typedef FileTable* PFILETABLE;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Sructure Name:      UAREA
//  Descrription:       Hold the inforrmation about the process file.                    
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct UAREA
{
    char ProcessName[20];
    PFILETABLE UFDT[MAXOPENFILES];
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Global variables or objects used in project            
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BootBlock bootobj;
Superblock superobj;
UAREA uareaobj;

PINODE head = NULL;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :   InitialiseUAREA
//  Description         :   It is used to initalise UAREA members
//  Author Name         :   Poorva Rohan Bhalerao
//  Date                :   13/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void InitialiseUAREA()
{
    strcpy(uareaobj.ProcessName, "Myexe");
    int i = 0;

    for(i = 0; i < MAXOPENFILES; i++)
    {
        uareaobj.UFDT[i] = NULL;
    }

    printf("CVFS : UAREA gets Initialised successfully\n");

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :   InitialiseSuperBlock
//  Description         :   It is used to initalise SuperBlock members
//  Author Name         :   Poorva Rohan Bhalerao
//  Date                :   13/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void InitialiseSuperBlock()
{
    superobj.TotalInodes = MAXINODE;
    superobj.FreeInodes = MAXINODE;

    printf("CVFS : Super Block gets Initialised successfully\n");
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :   CreateDILB
//  Description         :   It is used to create Linked List of Inodes
//  Author Name         :   Poorva Rohan Bhalerao
//  Date                :   13/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CreateDILB()
{
    int i = 1;
    PINODE newn = NULL;
    PINODE temp = head;

    for(i = 1; i <= MAXINODE; i++)                      // Inode creation
    {
        newn = (PINODE)malloc(sizeof(INODE));

        strcpy(newn->FileName, "\0");
        newn->InodeNumber = i;
        newn->FileSize = 0;
        newn->ActualFileSize = 0;
        newn->ReferenceCount = 0;
        newn->Permission = 0;
        newn->Buffer = NULL;
        newn->next = NULL;

        if(temp == NULL)                                // LL is empty
        {
            head = newn;
            temp = head;
        }
        else                                            // LL contains at least one node
        {
            temp->next = newn;
            temp = temp->next;
        }        
    }

    printf("CVFS : DILB created successfully\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :   StartAuxillaryDataInitialisation
//  Description         :   It is used to call all such functions which are 
//                          used to initialise auxillary data
//  Author Name         :   Poorva Rohan Bhalerao
//  Date                :   13/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void StartAuxillaryDataInitialisation()
{
    strcpy(bootobj.Informmation , "Booting Process of CVFS Done");

    printf("%s\n",bootobj.Informmation);

    InitialiseSuperBlock();

    CreateDILB();

    InitialiseUAREA();

    printf("CVFS : Auxillary Data Initialised Successfully\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :   DisplayHelp
//  Description         :   It is used to display help page
//  Author Name         :   Poorva Rohan Bhalerao
//  Date                :   14/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DisplayHelp()
{
    printf("-----------------------------------------------------------------------------------\n");
    printf("------------------------------CVFS Help Page---------------------------------------\n");
    printf("-----------------------------------------------------------------------------------\n"); 

    printf("man     : It is used to display manual page\n");
    printf("clear   : It is used to clear the terminal\n");
    printf("creat   : It is used to create new file\n");
    printf("write   : It is used to write the data into file\n");
    printf("read    : It is used to read the data from the file\n");
    printf("stat    : It is used to display statistical information\n");
    printf("unlink  : It is used to delete the file\n");
    printf("exit    : It is used to terminate CVFS\n");

    printf("-----------------------------------------------------------------------------------\n"); 

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :   ManPageDispaly
//  Description         :   It is used to display Manpage
//  Author Name         :   Poorva Rohan Bhalerao
//  Date                :   14/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void ManPageDisplay(char Name[])
{
    if(strcmp("ls", Name) == 0)
    {
        printf("About   : It is used to list the names of all files\n");
        printf("Usage   : ls\n");

    }
    else if(strcmp("man", Name) == 0)
    {
        printf("About           : It is used to display manual page\n");
        printf("Usage           : man command_name\n");
        printf("command_name    : It is name of command\n");

    }
    else if(strcmp("exit", Name) == 0)
    {
        printf("About   : It is used to terminate the shell\n");
        printf("Usage   : exit\n");
    }
    else
    {
        printf("No manual page for %s\n",Name);
    }
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Entry Point Function            
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    char str[80] = {'\0'};                                  // used to accept command from user
    char Command[5][20]  = {'\0'};                          // parts of command
    int iCount = 0;

    StartAuxillaryDataInitialisation();

    printf("-----------------------------------------------------------------------------------\n");
    printf("-------------------------CVFS started Successfully---------------------------------\n");
    printf("-----------------------------------------------------------------------------------\n");   

    // Infinite Listening shell
    while(1)                            // Unconditional listening loop
    {
        fflush(stdin);

        strcpy(str, "");

        printf("\nCVFS : > ");
        fgets(str,sizeof(str), stdin);                  // scanf("%s", str);

        iCount = sscanf(str, "%s %s %s %s %s", Command[0],Command[1], Command[2], Command[3], Command[4]);

        fflush(stdin);

        if(iCount == 1)
        {
            if(strcmp("exit",Command[0]) == 0)
            {
                printf("Thank you for using CVFS\n");
                printf("Deallocating all the allocated resources\n");

                break;
            }
            else if(strcmp("ls",Command[0]) == 0)
            {
                printf("Inside ls\n");
            }
            else if(strcmp("help", Command[0]) == 0)
            {
                DisplayHelp();
            }

        }// End of else if 1
        else if(iCount == 2)
        {
            if(strcmp("man",Command[0]) == 0)
            {
                ManPageDisplay(Command[1]);
            }



        }// End of else if 2
        else if(iCount == 3)
        {

        }// End of else if 3
        else if(iCount == 4)
        {

        }// End of else if 4
        else
        {
            printf("Command not found\n");
            printf("Please refer help option for more information\n");
        }// End of else    
    
    }// End of while

    return 0;
}// End of main
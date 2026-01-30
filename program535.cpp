//CVFS-6

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
//  Entry Point Function            
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    char str[80] = {'\0'};                                  // used to accept command from user
    char Command[4][20];                                    // parts of command
    int iCount = 0;

    StartAuxillaryDataInitialisation();

    printf("-----------------------------------------------------------------------------------\n");
    printf("-------------------------CVFS started Successfully---------------------------------\n");
    printf("-----------------------------------------------------------------------------------\n");   

    while(1)                            // Unconditional listening loop
    {
        fflush(stdin);

        strcpy(str, "");

        printf("\nCVFS : > ");
        fgets(str,sizeof(str), stdin);                  // scanf("%s", str);

        


    }

    return 0;
}
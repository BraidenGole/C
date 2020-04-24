/**
 *  FILE            :   fileHandler.H
 *  PROJECT         :   None
 *  PROGRAMMER      :   Braiden Gole
 *  FIRST VERSION   :   2020-04-23  
 *  DESCRIPTION     :   This file is used to make our program more organized
 *                      and readable.
 */
#ifndef _KFILEHANDLER
#define _KFILEHANDLER "fileHandler.h"

// Global string constants.
#define KDIDNOTSUPPLY "\n\t[ You did NOT supply a <inputFile> ]\n"
#define KCOULDNOTOPEN "\n\tCould not open your file at this time.\n"
#define KCOULDNOTCLOSE "\n\tFile did not close properly !\n"
#define KCOULDNOTRENAME "\n\tSystem has failed to rename your file.\n"

// Global numeric constants.
#define K3000BYTES 3000
#define K100BYTES 100

// Function prototypes.
const int displayResult(FILE* pFileToDisplay, 
const char* kpsNameOfFile, const char* kpsFileMode);
#endif
/**
 *  FILE            :   weaponWheel.c
 *  PROJECT         :   None
 *  PROGRAMMER      :   Braiden Gole
 *  FIRST VERSION   :   2020-06-25
 *  DESCRIPTION     :   This file contains the functions for our weapon wheel.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Header file.
#include "weaponWheel.h"

// Function prototypes.
void newLineRemover(char* psInputWithNewLine);

/**
 *  FUNCTION        :   bAddWeapon
 *  DESCRIPTION     :   This function will add a new weapon to the weapon wheel.
 *  PARAMETERS      :   ppWeaponHead, ppWeaponTail
 *  RETURNS         :   ppWeaponHead
 */
const bool bAddWeapon(struct Weapon** ppWeaponHead, struct Weapon** ppWeaponTail)
{
    struct Weapon* pNewWeapon = NULL;
    pNewWeapon = (struct Weapon*)malloc(sizeof(struct Weapon));

    // Check the system for sufficient memory.
    if (pNewWeapon == NULL) { return false; }
    else
    {
        // We have memory for a new weapon entry.
        getchar();
        printf(KPROMPTFORWEAPON);
        fgets(pNewWeapon->arsWeapon, K100BYTES, stdin);
        newLineRemover(pNewWeapon->arsWeapon);
        
        // Is the weapon wheel empty ?
        if (*ppWeaponHead == NULL) 
        {   
            // Fill the data in of the head and tail node.
            *ppWeaponHead = pNewWeapon;
            *ppWeaponTail = pNewWeapon;

            // Insert the nodes to the proper position.
            pNewWeapon->pPrev = *ppWeaponTail;
            pNewWeapon->pNext = *ppWeaponHead;
        }
        pNewWeapon->pNext = *ppWeaponHead;
        (*ppWeaponHead)->pPrev = pNewWeapon;
        pNewWeapon->pPrev = *ppWeaponTail;
        (*ppWeaponTail)->pNext = pNewWeapon;
        *ppWeaponHead = pNewWeapon;
    }
    return true;
}

/**
 *  FUNCTION        :   psWieldNewWeapon
 *  DESCRIPTION     :   This function allows the user to wield a new
 *                      weapon for the weapon wheel.
 *  PARAMETERS      :   ppWeaponHead, psWeaponToWield
 *  RETURNS         :   psWeaponToWield, KDOESNOTEXIST
 */
const char* psWieldNewWeapon(struct Weapon* ppWeaponHead, char* psWeaponToWield)
{
    struct Weapon* pHead = ppWeaponHead;
    do
    {   
        // Search for a matching weapon in the weapon wheel.
        if ((strcmp(pHead->arsWeapon, psWeaponToWield)) == 0)
        {
            return psWeaponToWield;
        }
        pHead = pHead->pNext;
    } while (pHead != ppWeaponHead);
    return KDOESNOTEXIST;
}

/**
 *  FUNCTION        :   bDeleteWeaponAtHead
 *  DESCRIPTION     :   This function allows the user to delete
 *                      a single weapon from the "head" of the weapon wheel.
 *  PARAMETERS      :   ppWeaponHead, ppWeaponTail
 *  RETURNS         :   true, false
 */
const bool bDeleteWeaponAtHead(struct Weapon** ppWeaponHead, struct Weapon** ppWeaponTail)
{
    struct Weapon* pTempNode = NULL;
    pTempNode = *ppWeaponHead;

    // Is the weapon wheel empty ?
    if (*ppWeaponHead == NULL) { return false; }
    else if ((*ppWeaponHead)->pNext == *ppWeaponHead)
    {
        *ppWeaponHead = NULL;
        *ppWeaponTail = NULL;
        free(pTempNode);
        return true;
    }
    // We have more than one weapon in the list.
    *ppWeaponHead = (*ppWeaponHead)->pNext;
    (*ppWeaponHead)->pPrev = *ppWeaponTail;
    (*ppWeaponTail)->pNext = *ppWeaponHead;
    free(pTempNode);
    return true;
}

/**
 *  FUNCTION        :   wipeWeaponWheel
 *  DESCRIPTION     :   This function will clear every dynamically allocated instance
 *                      in the weapon wheel once we are done with it.
 *  PARAMETERS      :   pWeaponHead
 *  RETURNS         :   None
 */
void wipeWeaponWheel(struct Weapon* pWeaponHead)
{
    struct Weapon* pThisWeapon = NULL;
    struct Weapon* pNextWeapon = NULL;

    pThisWeapon = pWeaponHead;

    do
    {   
        pNextWeapon = pThisWeapon->pNext;
        free(pThisWeapon);
        pThisWeapon = pNextWeapon;
    } while (pThisWeapon != pWeaponHead);
}

/**
 *  FUNCTION        :   newLineRemover
 *  DESCRIPTION     :   This function will remove the new-line
 *                      that gets appended to the end of input.
 *  PARAMETERS      :   psInputWithNewLine
 *  RETURNS         :   None
 */
void newLineRemover(char* psInputWithNewLine)
{
    char* psFindTheNewLine = strchr(psInputWithNewLine, '\n');
    if (psFindTheNewLine != NULL) { psFindTheNewLine = NULL; }
}

/**
 *  FUNCTION        :   showWeaponWheel
 *  DESCRIPTION     :   This function will display the weapon selection
 *                      which is represented by the "Weapon Wheel" this allows
 *                      us to choose which weapon we would like that exists in the list.
 *  PARAMETERS      :   pWeaponHead
 *  RETURNS         :   None
 */
void showWeaponWheel(struct Weapon* pWeaponHead)
{   
    struct Weapon* pWheel = pWeaponHead;
    while (pWheel->pNext != pWeaponHead)
    {
        printf("\t%s", pWheel->arsWeapon);
        pWheel = pWheel->pNext;
    }
}   

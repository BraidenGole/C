/**
 *  FILE            :   weaponWheel.c
 *  PROJECT         :   None
 *  PROGRAMMER      :   Braiden Gole
 *  FIRST VERSION   :   2020-06-25 - (updated 2021-01-29) [Improvment] !
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
 *  FUNCTION        :   addWeapon
 *  DESCRIPTION     :   This function will add a new weapon to the weapon wheel.
 *  PARAMETERS      :   weaponHead, weaponTail
 *  RETURNS         :   weaponHead
 */
const bool addWeapon(struct Weapon** weaponHead, struct Weapon** weaponTail)
{
    struct Weapon* newWeapon = NULL;
    newWeapon = (struct Weapon*)malloc(sizeof(struct Weapon));

    // Check the system for sufficient memory.
    if (newWeapon == NULL) 
    { 
        return false;
    }
    else
    {
        // We have memory for a new weapon entry.
        getchar();
        printf(KPROMPTFORWEAPON);
        fgets(newWeapon->arsWeapon, K100BYTES, stdin);
        newLineRemover(newWeapon->arsWeapon);
        
        if (*weaponHead == NULL) 
        {   
            *weaponHead = newWeapon;
            *weaponTail = newWeapon;

            newWeapon->pPrev = *weaponTail;
            newWeapon->pNext = *weaponHead;
        }
        newWeapon->pNext = *weaponHead;
        (*weaponHead)->pPrev = newWeapon;
        newWeapon->pPrev = *weaponTail;
        (*weaponTail)->pNext = newWeapon;
        *weaponHead = newWeapon;
    }
    return true;
}

/**
 *  FUNCTION        :   wieldNewWeapon
 *  DESCRIPTION     :   This function allows the user to wield a new
 *                      weapon for the weapon wheel.
 *  PARAMETERS      :   weaponHead, weaponToWield
 *  RETURNS         :   weaponToWield, KDOESNOTEXIST
 */
const char* wieldNewWeapon(struct Weapon* weaponHead, char* weaponToWield)
{
    struct Weapon* pHead = weaponHead;
    do
    {   
        // Search for a matching weapon in the weapon wheel.
        if ((strcmp(pHead->arsWeapon, weaponToWield)) == 0)
        {
            return weaponToWield;
        }
        pHead = pHead->pNext;
    } while (pHead != weaponHead);
    return KDOESNOTEXIST;
}

/**
 *  FUNCTION        :   deleteWeaponAtHead
 *  DESCRIPTION     :   This function allows the user to delete
 *                      a single weapon from the "head" of the weapon wheel.
 *  PARAMETERS      :   weaponHead, weaponTail
 *  RETURNS         :   true, false
 */
const bool deleteWeaponAtHead(struct Weapon** weaponHead, struct Weapon** weaponTail)
{
    struct Weapon* pTempNode = NULL;
    pTempNode = *weaponHead;

    // Is the weapon wheel empty ?
    if (*weaponHead == NULL) 
    { 
        return false;
    }
    else if ((*weaponHead)->pNext == *weaponHead)
    {
        *weaponHead = NULL;
        *weaponTail = NULL;
        free(pTempNode);
        return true;
    }
    // We have more than one weapon in the list.
    *weaponHead = (*weaponHead)->pNext;
    (*weaponHead)->pPrev = *weaponTail;
    (*weaponTail)->pNext = *weaponHead;
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
    if (psFindTheNewLine != NULL) 
    { 
        psFindTheNewLine = NULL;
    }
}

/**
 *  FUNCTION        :   showWeaponWheel
 *  DESCRIPTION     :   This function will display the weapon selection
 *                      which is represented by the "Weapon Wheel" this allows
 *                      us to choose which weapon we would like that exists in the list.
 *  PARAMETERS      :   weaponHead, weaponTail
 *  RETURNS         :   None
 */
void showWeaponWheel(struct Weapon* pWeaponHead, struct Weapon* weaponTail)
{   
    pWeaponHead = weaponTail;
    do
    {
        printf("\t%s", pWeaponHead->arsWeapon);
        pWeaponHead = pWeaponHead->pNext;
    } while (pWeaponHead != weaponTail);
}   

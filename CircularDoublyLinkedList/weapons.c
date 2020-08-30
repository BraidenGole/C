/**
 *  FILE            :   weapons.c
 *  PROJECT         :   None
 *  PROGRAMMER      :   Braiden Gole
 *  FIRST VERSION   :   2020-06-25
 *  DESCRIPTION     :   This is the implementation of a circular linked list.
 * 
 *          Note:   This circular linked list represents a weapon wheel that
 *                  you would find in a video game like Red Dead Redemption 2 where you can
 *                  cycle through weapons.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Header files.
#include "weaponWheel.h"

int main(void)
{   
    struct Weapon* pHead = NULL;
    struct Weapon* pTail = NULL;

    int iSelection = 0;
    char arsWeaponToWield[K100BYTES] = {""};

    bool bWeaponWheel = true;
    while (bWeaponWheel)
    {   
        /** -- Weapon Menu -- **/
        printf(KMENUHEADER);
        printf(KSELECTION1);
        printf(KSELECTION2);
        printf(KSELECTION3);
        printf(KSELECTION4);
        printf(KSELECTION5);
        printf(KPROMPTFORSELECTION);
        if ((fscanf(stdin, "%i", &iSelection)) == 0)
        {
            fprintf(stderr, KNOCHARACTERSALLOWED);
            fflush(stdin);
        }
        printf("\n");

        // Associate the users selection with the proper operation.
        switch (iSelection)
        {
            case 1:
                bAddWeapon(&pHead, &pTail);
                break;
            case 2:
                // Show the weapon wheel so the user can choose a weapon to wield.
                showWeaponWheel(pHead);

                getchar();
                printf(KPROMPTFORWIELDNEWWEAPON);
                fgets(arsWeaponToWield, K100BYTES, stdin);
                printf("\n\tWEAPON UPDATED: %s", psWieldNewWeapon(pHead, arsWeaponToWield));
                break;
            case 3:
                if ((bDeleteWeaponAtHead(&pHead, &pTail)) == false) { fprintf(stderr, KEMPTY); }
                printf(KDELETED);
                break;
            case 4:
                showWeaponWheel(pHead);
                break;
            case 5:
                /** -- Free all Dynamicall allocated memory -- **/
                wipeWeaponWheel(pHead);
                bWeaponWheel = false;
        }
    }
    return 0;
}
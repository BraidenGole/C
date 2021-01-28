/**
 *  FILE            :   weapons.c
 *  PROJECT         :   None
 *  PROGRAMMER      :   Braiden Gole
 *  FIRST VERSION   :   2020-06-25 - (2021-01-27)
 *  DESCRIPTION     :   This is the implementation of a circular linked list.
 * 
 *          Note:   This circular linked list represents a weapon wheel that
 *                  you would find in a video game like Red Dead Redemption 2 where you can
 *                  cycle through weapons.
 *          
 *          (Improvment): Display function will now display every time instead of after the second
 *                        entry has been made, it will now display on the first entry !
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Header files.
#include "weaponWheel.h"

int main(void)
{   
    struct Weapon* head = NULL;
    struct Weapon* tail = NULL;

    int selection = 0;
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
        if ((fscanf(stdin, "%i", &selection)) == 0)
        {
            fprintf(stderr, KNOCHARACTERSALLOWED);
            fflush(stdin);
        }
        printf("\n");

        // Associate the users selection with the proper operation.
        switch (selection)
        {
            case 1:
                addWeapon(&head, &tail);
                break;
            case 2:
                // Show the weapon wheel so the user can choose a weapon to wield.
                showWeaponWheel(head, tail);

                getchar();
                printf(KPROMPTFORWIELDNEWWEAPON);
                fgets(arsWeaponToWield, K100BYTES, stdin);
                printf("\n\tWEAPON UPDATED: %s", wieldNewWeapon(head, arsWeaponToWield));
                break;
            case 3:
                if ((deleteWeaponAtHead(&head, &tail)) == false) 
                { 
                    fprintf(stderr, KEMPTY);
                }
                printf(KDELETED);
                break;
            case 4:
                showWeaponWheel(head, tail);
                break;
            case 5:
                /** -- Free all Dynamicall allocated memory -- **/
                wipeWeaponWheel(head);
                bWeaponWheel = false;
        }
    }
    return 0;
}

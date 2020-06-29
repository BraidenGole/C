/**
 *  FILE            :   weaponWheel.h
 *  PROJECT         :   None
 *  PROGRAMMER      :   Braiden Gole
 *  FIRST VERSION   :   2020-06-25
 *  DESCRIPTION     :   This file holds all of our function prototypes
 *                      and the blueprint to each selection in the menu that
 *                      would represent the "Node" in this case.
 */
#ifndef _KWEAPONWHEEL
#define _KWEAPONWHEEL "weaponWheel."

// Global string constants.
#define KMENUHEADER "\n -- Weapon Wheel --\n"
#define KSELECTION1 "\n\t1. Add a weapon."
#define KSELECTION2 "\n\t2. Wield a weapon."
#define KSELECTION3 "\n\t3. Delete a weapon."
#define KSELECTION4 "\n\t4. Show Weapon Wheel."
#define KSELECTION5 "\n\t5. Quit.\n\n"
#define KPROMPTFORWEAPON "\tEnter in a weapon: "
#define KPROMPTFORWIELDNEWWEAPON "\tWield which weapon: "
#define KPROMPTFORSELECTION "\tSelect an operation: "
#define KNOCHARACTERSALLOWED "\n\tNo characters allowed !\n"
#define KOUTOFMEMORY "\n\tOut of Memory !\n"
#define KEMPTY "\t__Empty__ !\n"
#define KDOESNOTEXIST "DoesNotExist !\n"
#define KDELETED "\t__Deleted__!\n"

// Global numeric constants.
#define K100BYTES 100

// Declare the weapon wheel node.
struct Weapon
{   
    char arsWeapon[K100BYTES];
    struct Weapon* pNext;
    struct Weapon* pPrev;
};

// Function prototypes.
const bool bAddWeapon(struct Weapon** pWeaponHead, struct Weapon** pPrev);
const char* psWieldNewWeapon(struct Weapon** pWeaponHead, char* psWeaponToWield);
const bool bDeleteWeaponAtHead(struct Weapon** pWeaponHead, struct Weapon** pWeaponTail);
void showWeaponWheel(struct Weapon** pWeaponHead);
void wipeWeaponWheel(struct Weapon** pWeaponHead);
#endif


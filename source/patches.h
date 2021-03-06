/*
*   patches.h
*       by Reisyukaku
*/
#ifndef PATCHES_INC
#define PATCHES_INC

#include "types.h"

#define FIRM 0x24000000
#define KERNEL9 (FIRM + 0x66A00)
#define PROC9 (FIRM + 0x7D700)

#define K9_ADDR 0x08006000
#define P9_ADDR 0x08028000

/*
*   Emunand
*/
//Addresses to patch
u32 emuCode = KERNEL9 + (0x0801A4C0 - K9_ADDR);
u32 emuHook1 = KERNEL9 + (0x0801B3D4 - K9_ADDR);
u32 emuHook2 = PROC9 + (0x080282F8 - P9_ADDR);
u32 emuHook3 = PROC9 + (0x0807877E - P9_ADDR);
u32 emuHook4 = PROC9 + (0x080787BE - P9_ADDR);
//Patches
u8 eh1[0x2C] = {
    0x03, 0x00, 0x36, 0x00, 0x00, 0x00, 0x10, 0x10, 0x01, 0x00, 0x00, 0x01, 0x03, 0x00, 0x36, 0x00, 
    0x00, 0x00, 0x00, 0x20, 0x01, 0x01, 0x01, 0x01, 0x03, 0x06, 0x20, 0x00, 0x00, 0x00, 0x00, 0x08, 
    0x01, 0x01, 0x01, 0x01, 0x03, 0x06, 0x1C, 0x00, 0x00, 0x00, 0x02, 0x08
    };
u8 eh2[0x14] = {
    0x03, 0x4A, 0x05, 0x21, 0x25, 0x20, 0x2F, 0xF0, 0xAB, 0xF8, 0x37, 0xF0, 0x6F, 0xFB, 0x70, 0xBD, 
    0xC8, 0xA6, 0x01, 0x08
    };      //Sets Slot0x25KeyX           
u8 eh3[0x0A] = {0x01, 0x4C, 0x20, 0x47, 0x00, 0x00, 0xC0, 0xA4, 0x01, 0x08};    //Branch to first emunand function
u8 eh4[0x0A] = {0x01, 0x4C, 0x20, 0x47, 0x00, 0x00, 0xB0, 0xA5, 0x01, 0x08};    //Branch to second emunand function


/*
*   Sig checks
*/
//Addresses to patch
u32 patch1 = PROC9 + (0x08063374 - P9_ADDR);
u32 patch2 = PROC9 + (0x0805D498 - P9_ADDR);
//Patches
u8 p1[2] = {0x00, 0x20};
u8 p2[4] = {0x00, 0x20, 0x70, 0x47};


/*
*   Arm9 thread
*/
//Addresses to patch
u32 threadCode = KERNEL9 + (0x0801A6E0 - K9_ADDR);
u32 threadHook1 = PROC9 + (0x080860B0 - P9_ADDR);
u32 threadHook2 = PROC9 + (0x080860E4 - P9_ADDR);
//Patches
u8 th1[4] = {0x2C, 0xF0, 0x9F, 0xE5}; //ldr pc, =0x080860E4
u8 th2[4] = {0xE0, 0xA6, 0x01, 0x08};

#endif
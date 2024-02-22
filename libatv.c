/* SPDX-License-Identifier: MIT */

#include <libatv.h>

PMACH_BOOTARGS BootArgs;

/* Set up command line and enable verbose mode */
static
void SetupCmdLine(char *CmdLine) {
    /* Check if we should enable verbose mode */
    if (strstr(CmdLine, "-v") || strstr(CmdLine, "-s")) {
        /* Enable verbose printing in libatv */
        ClearScreen(TRUE, 0x00000000);
        debug_printf("Booting in Verbose Mode. ");
    }
    debug_printf("Command line arguments: %s\n", BootArgs->CmdLine);
}

void EarlyInit(u32 BootArgPtr) {
    BootArgs = (PMACH_BOOTARGS) BootArgPtr;
    EFI_TIME Time;
    // set up screen
    SetupScreen();
    // set up command line
    SetupCmdLine(BootArgs->CmdLine);
    trace("%s(): Starting Apple TV loader.\n", "EarlyInit");
    
    Time = GetTimeFromUefi();
    debug_printf("Current time: %02d/%02d/%02d %02d:%02d:%02d\n", Time.Year,
                Time.Month, Time.Day, Time.Hour, Time.Minute, Time.Second);
    
    fail(0, __FILE__, __LINE__, "EarlyInit");
}

void fail(u8 ErrorCode, char *File, u32 Line, char *Function) {
    ChangeColors(0xFFFF00FF, 0x00000000);
    printf("We're sorry, an error has occurred in %s() (%s:%d)!\nError code: %d\n", 
            Function, File, Line, ErrorCode);
    printf("Please report this bug to the developer of this bootloader.\n");
    __halt();
}
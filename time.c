/* SPDX-License-Identifier: MIT */

#include <libatv.h>

EFI_TIME GetTimeFromUefi() {
    EFI_STATUS Status;
    EFI_TIME Time = {0};
    
    // set up global system table
    EFI_SYSTEM_TABLE *GlobalSystemTable = (EFI_SYSTEM_TABLE *) BootArgs->EfiSystemTable;
    
    // get time
    Status = GlobalSystemTable->RuntimeServices->GetTime(&Time, NULL);
    if (Status != EFI_SUCCESS) {
        error("Cannot get time. Status = %d\n", Status);
    }
    
    // check validity of time
    if (Time.Year < 2024) {
        warn("Incorrect time detected! (CMOS battery failure?) Setting time to 2024/01/01 00:00:00\n");
        
        // set time
        Time.Year = 2024;
        Time.Month = 01;
        Time.Day = 01;
        Time.Hour = 00;
        Time.Minute = 00;
        Time.Second = 00;
        Time.Nanosecond = 0;
        
        Status = GlobalSystemTable->RuntimeServices->SetTime(&Time);
        if (Status != EFI_SUCCESS) {
            error("Cannot set time. Status = %d\n", Status);
        }        
    }
        
    return Time;
}

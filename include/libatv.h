/* SPDX-License-Identifier: MIT */

#pragma once

// libatv natives
#include "boot_args.h"
#include "mach.h"
#include "types.h"
#include "utils.h"
#include "console.h"
#include "ioports.h"
#include "time.h"

// uefi
#include "uefi/Uefi.h"


extern bool WrapperVerbose;

extern void fail(u8 ErrorCode, char *File, u32 Line, char *Function);

#define __halt() __asm__ __volatile__ ("hlt" : : )
/* SPDX-License-Identifier: MIT */

#pragma once

#include "types.h"

#define MACH_CMDLINE 1024

/* Video parameters passed to kernel. */
typedef struct {
    u32 BaseAddress; /* Base video address */
    u32 DisplayMode; /* Display mode specifier */
    u32 Pitch; /* Bytes per row */
    u32 Width; /* Display width in pixels */
    u32 Height; /* Display height in pixels */
    u32 Depth; /* Display depth in bits */
} __attribute__((aligned(4))) MACH_VIDEO, *PMACH_VIDEO;

/* Boot arguments struct passed into loader. A pointer to this struct is located in the EAX register upon kernel load.
 * See xnu-1228 pexpert/pexpert/i386/boot.h.
 */

typedef struct {
    u16 Revision; /* Revision of this structure */
    u16 Version; /* Version of this structure */

    char CmdLine[MACH_CMDLINE]; /* Command line data */

    u32 EfiMemoryMap; /* Location of EFI memory map */
    u32 EfiMemoryMapSize; /* Size of EFI memory map */
    u32 EfiMemoryDescriptorSize; /* Size of EFI descriptor */
    u32 EfiMemoryDescriptorVersion; /* Version of EFI memory descriptors */

    MACH_VIDEO Video; /* Video parameters */

    u32 DeviceTree; /* Pointer to base of Apple IODeviceTree */
    u32 DeviceTreeLength; /* Length of device tree */

    u32 KernelBaseAddress; /* Beginning of kernel as specified by `-segaddr __TEXT` */
    u32 KernelSize; /* Size of kernel and firmware */

    u32 EfiRuntimeServicesPageStart; /* Address of defragmented runtime pages */
    u32 EfiRuntimeServicesPageCount; /* Number of EFI pages */
    u32 EfiSystemTable; /* EFI System Table */

    u8 EfiMode; /* EFI mode: 32 = 32 bit EFI, 64 = 64 bit EFI */

    u8 __reserved1[3];
    u8 __reserved2[7];
} __attribute__((aligned(4))) MACH_BOOTARGS, *PMACH_BOOTARGS;

extern PMACH_BOOTARGS BootArgs;
/* SPDX-License-Identifier: MIT */

#pragma once

#define MACHO_MAGIC 0xFEEDFACE /* Mach-O Magic number */
#define MACHO_CIGAM 0xCEFAEDFE /* Big-endian representation */
#define MACHO_OBJECT 0x1 /* Relocatable object file */

#define MACHO_LC_SEGMENT 0x1 /* Segment to be mapped */

/* Mach-O header */
typedef struct {
    u32 MagicNumber; /* Mach-O magic number. */

    s32 CpuType; /* CPU type */
    s32 CpuSubtype; /* CPU subtype */

    u32 FileType; /* Type of Mach-O file */

    u32 NumberOfCmds; /* Number of load commands */
    u32 SizeOfCmds; /* Size of all load commands */

    u32 Flags; /* Executable flags */
} MACHO_HEADER, *PMACHO_HEADER;

typedef struct {
    u32 Command; /* LC_SEGMENT */
    u32 CommandSize; /* Size of segment command */

    char SegmentName[16]; /* Name of segment */

    u32 VMAddress; /* Virtual memory address of this segment */
    u32 VMSize; /* Virtual memory size of this segment */

    u32 FileOffset; /* File offset of this segment */
    u32 FileSize; /* Amount to map from the file */

    s32 MaximumProtection; /* Maximum virtual memory protection */
    s32 InitialProtection; /* Initial virtual memory protection */

    u32 NumberOfSections; /* Number of sections in this segment */

    u32 Flags; /* Segment flags */
} MACHO_SEGMENT_COMMAND, *PMACHO_SEGMENT_COMMAND;

typedef struct {
    char SectionName[16]; /* Name of this section */
    char SegmentName[16]; /* Segment this section goes in */

    u32 Address; /* Memory address of this section */
    u32 Size; /* Size of this section in bytes */
    u32 Offset; /* File offset for this section */

    u32 Alignment; /* Alignment of section */

    u32 RelocationOffset; /* File offset of relocation entries */
    u32 NumberOfRelocation; /* Number of relocation entries */

    u32 Flags; /* Section flags */

    u32 Reserved1;
    u32 Reserved2;
} MACHO_SECTION, *PMACHO_SECTION;

extern MACHO_HEADER _mh_execute_header; /* Defined by Mach-O linker */

extern u8 *GetSectionDataFromHeader(PMACHO_HEADER Header, const char *SegmentName, const char *SectionName,
                                    u32 *Size);
/* SPDX-License-Identifier: MIT */

#pragma once

/* UNIX-style stdint types */
typedef char                int8_t;
typedef char                bool;
typedef unsigned char       uint8_t;

typedef short               int16_t;
typedef unsigned short      uint16_t;

typedef long                int32_t;
typedef unsigned long       uint32_t;

typedef long long           int64_t;
typedef unsigned long long  uint64_t;

/* Shortened types */
typedef char                s8;
typedef unsigned char       u8;

typedef short               s16;
typedef unsigned short      u16;

typedef long                s32;
typedef unsigned long       u32;

typedef long long           s64;
typedef unsigned long long  u64;

/* Miscellaneous types */
typedef __SIZE_TYPE__       size_t;
typedef __UINTPTR_TYPE__    uintptr_t;

/* for U-Boot */
typedef unsigned int uint;
typedef unsigned long ulong;
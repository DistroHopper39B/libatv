/* SPDX-License-Identifier: MIT */

#pragma once

#include <stdarg.h>

typedef u8* FRAMEBUFFER;

#define COM1 0x3F8

extern int vsprintf(char *buf, const char *fmt, va_list args);
extern int sprintf(char * buf, const char *fmt, ...);

/* Print/debug print functions */
extern void printf(const char *szFormat, ...);

#define debug_printf(...)   if (WrapperVerbose) \
                            printf(__VA_ARGS__)
#define trace(...)          debug_printf("(%s:%d) trace: ", __FILE__, __LINE__); \
                            debug_printf(__VA_ARGS__)
#define warn(...)           printf("(%s:%d) warning: ", __FILE__, __LINE__); \
                            printf(__VA_ARGS__)
#define error(...)          printf("(%s:%d) error: ", __FILE__, __LINE__); \
                            printf(__VA_ARGS__)
#define fatal(...)          printf("(%s:%d) FATAL: ", __FILE__, __LINE__); \
                            printf(__VA_ARGS__)

extern void ClearScreen(bool VerboseEnable, u32 RgbaValue);
extern void SetupScreen();
extern void ChangeColors(u32 Foreground, u32 Background);

extern PMACH_VIDEO Video;
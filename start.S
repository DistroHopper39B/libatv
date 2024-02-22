/* SPDX-License-Identifier: MIT */

.text
.globl start

start:
    # Push BootArgs pointer to C loader
    pushl %eax
    # Jump to C
	call _EarlyInit
	# Halt the system
	hlt
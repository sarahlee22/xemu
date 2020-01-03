/* Part of the Xemu project, please visit: https://github.com/lgblgblgb/xemu
   Copyright (C)2016-2020 LGB (Gábor Lénárt) <lgblgblgb@gmail.com>

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA */

#ifdef	XEMU_XEMU_ARCH_SYS_H_INCLUDED
#	error "xemu/arch-sys.h cannot be included multiple times (and it's included by C compiler command line)."
#endif
#define	XEMU_XEMU_ARCH_SYS_H_INCLUDED

#ifndef	_ISOC11_SOURCE
#	define	_ISOC11_SOURCE
#endif

#ifdef	__EMSCRIPTEN__
#	define	XEMU_ARCH_HTML
#	define	XEMU_ARCH_NAME	"html"
#	ifndef	DISABLE_DEBUG
#		define	DISABLE_DEBUG
#	endif
//#	define	XEMU_OLD_TIMING
#elif	_WIN64
#	define	XEMU_ARCH_WIN64
#	define	XEMU_ARCH_WIN
#	define	XEMU_ARCH_NAME	"win64"
#	define	XEMU_SLEEP_IS_USLEEP
#elif	_WIN32
#	define	XEMU_ARCH_WIN32
#	define	XEMU_ARCH_WIN
#	define	XEMU_ARCH_NAME	"win32"
#	define	XEMU_SLEEP_IS_USLEEP
#elif	__APPLE__
	// Actually, MacOS / OSX is kinda UNIX, but for some minor reasons we handle it differently here
#	include	<TargetConditionals.h>
#	ifndef	TARGET_OS_MAC
#		error	"Unknown Apple platform (TARGET_OS_MAC is not defined by TargetConditionals.h)"
#	endif
#	define	XEMU_ARCH_NATIVE
#	define	XEMU_ARCH_OSX
#	define	XEMU_ARCH_MAC
#	define	XEMU_ARCH_UNIX
#	define	XEMU_ARCH_NAME	"osx"
#	define	XEMU_SLEEP_IS_NANOSLEEP
#elif	defined(__unix__) || defined(__unix) || defined(__linux__) || defined(__linux)
#	define	XEMU_ARCH_NATIVE
#	define	XEMU_ARCH_UNIX
#	if	defined(__linux__) || defined(__linux)
#		define	XEMU_ARCH_LINUX
#		define	XEMU_ARCH_NAME	"linux"
#	else
#		define	XEMU_ARCH_NAME	"unix"
#	endif
#	define	XEMU_SLEEP_IS_NANOSLEEP
#else
#	error	"Unknown target OS architecture."
#endif

#include "xemu-target.h"

#if defined(XEMU_ARCH_HTML) && !defined(CONFIG_EMSCRIPTEN_OK)
#	error "Sorry, emscripten is not yet validated for this sub-project (CONFIG_EMSCRIPTEN_OK is not defined in xemu-target.h) ..."
#endif

# PCRd Release Notes

## Current Version: 0.13

**Updated by**: Steven Haigh
**Website**: http://www.crc.id.au/pcrd
**Status**: Legacy software maintained for historical compatibility

### Version 0.13 Changes (2026)

- Fixed all compiler warnings for clean build on modern systems
- Created pcrd.h header file with structure definitions and function prototypes
- Removed Solaris support (supports Linux and FreeBSD)
- Changed default serial port to /dev/ttyUSB0
- Updated Makefile: renamed 'foo' target to 'help', made 'linux' the default target
- Fixed format string warnings and type safety issues
- Improved code organization and maintainability
- Updated all documentation to reflect current state
- Removed platform-specific preprocessor conditionals (same build for Linux and FreeBSD)

### Version 0.12 Changes (2006)

- Updated source code to compile with modern GCC versions
- Should now compile on most modern Linux distributions
- Code cleanup and compatibility fixes

---

## Version History

---

RCS file: RCS/pcrd.c,v  
Working file: pcrd.c  
head: 1.15  
branch:  
locks: strict  
access list:  
symbolic names:  
keyword substitution: kv  
total revisions: 15;    selected revisions: 15  
description:  
Initial version of pcrd, the PCR1000 control daemon / command line interface.

---

## Revision 1.15
**date:** 1999/06/29 23:04:45 | **author:** cwalker | **state:** Exp  
**lines:** +5 -5

Added a usleep(50000) to the wait loop for the socket communications.  
This will keep the radio command buffer from filling up and taking  
a long time to reply to commands from the remote system. This should  
fix the latency problems that people were having when trying to  
write GUI interfaces to this program. It was dawg slow when the  
radio buffer had filled up.

---

## Revision 1.14
**date:** 1999/03/15 21:52:57 | **author:** cwalker | **state:** Exp  
**lines:** +157 -38

Updated and changed the socket reporting for freq. offset, squelch  
state, signal, mode, and filter. This is more than likely the  
last major (or minor) update to pcrd. I will be changing the  
overall form of the program from a C based, single radio type  
program, to a C++ based, write a radio class and drop it in  
type of program, that will have support for the PCR-1000  
and the Kenwood TS-440 to start with (as these are the only  
two radios that I own that have serial port control).

Stay tuned.

---

## Revision 1.13
**date:** 1999/01/31 21:03:21 | **author:** cwalker | **state:** Exp  
**lines:** +28 -24

Filter data if the reply packet to a query is 'bad'.  
Indicate uptime of the daemon.  
More minor cleanup.

---

## Revision 1.12
**date:** 1999/01/29 01:39:40 | **author:** cwalker | **state:** Exp  
**lines:** +94 -46

Added a timeout so that the daemon will exit if communications  
are lost with the target radio.

Added some other minor refinements. Version to 0.07

This code seems stable and has had uptimes in excess of two days  
with the last revision. Now it will be time to add more features  
and muck things up a bit. :-)

---

## Revision 1.11
**date:** 1999/01/27 02:00:24 | **author:** cwalker | **state:** Exp  
**lines:** +34 -11

Added reporting of remote connected host on the socket.

---

## Revision 1.10
**date:** 1999/01/26 02:28:14 | **author:** cwalker | **state:** Exp  
**lines:** +4 -3

Don't do socket setup unless we are in daemon mode.

---

## Revision 1.9
**date:** 1999/01/24 20:52:32 | **author:** cwalker | **state:** Exp  
**lines:** +47 -22

Changed reporting so that f_offset will not be shown unless  
in nfm mode. Other minor code cleanup. Version to 0.05.

---

## Revision 1.8
**date:** 1999/01/23 15:34:05 | **author:** root | **state:** Exp  
**lines:** +70 -7

Fixed the problem where the newly connected socket from the remote system  
was not set to non blocking. Now it is, and the radio gets commands sent  
to it during the time that pcrd is waiting for a new command from the  
remote system. Cleaned up a spelling error or two.

---

## Revision 1.7
**date:** 1999/01/23 02:27:49 | **author:** root | **state:** Exp  
**lines:** +378 -171

Added uptime counter, displayed when connected to pcrd socket.  
Added polling of radio power status while waiting for a connected  
socket to deliver command data to pcrd. This allows infinite  
amounts of time to pass while typing in a command string into a  
telnet session without the radio timing itself out and turning  
off. There was no way to recover from this except to kill the  
daemon and restart it with the -i option. Silly me.

---

## Revision 1.6
**date:** 1999/01/21 22:06:54 | **author:** root | **state:** Exp  
**lines:** +3 -0

Fixed the bug that I added to socket command line parsing in the last clean up rev!

---

## Revision 1.5
**date:** 1999/01/21 20:55:11 | **author:** root | **state:** Exp  
**lines:** +452 -444

More cleanup, code style. Nothing major. This will be Release 0.03

---

## Revision 1.4
**date:** 1999/01/20 23:51:41 | **author:** root | **state:** Exp  
**lines:** +159 -115

Added PID reporting when the daemon mode starts. Added -X command to socket  
mode to make the daemon exit.

---

## Revision 1.3
**date:** 1999/01/20 01:50:02 | **author:** root | **state:** Exp  
**lines:** +5 -1

Fixed exiting on a signal, and reporting of child PID when entering daemon mode.

---

## Revision 1.2
**date:** 1999/01/20 01:28:36 | **author:** root | **state:** Exp  
**lines:** +154 -57

Added the daemon support, and signal support. Getting closer to initial release.

---

## Revision 1.1
**date:** 1999/01/19 23:34:34 | **author:** root | **state:** Exp

Initial revision

---

## Project Summary

**RCS file**: RCS/pcrd.c,v  
**Working file**: pcrd.c  
**Head revision**: 1.15  
**Total revisions**: 15  
**Branches**: none  
**Locks**: strict

### Description

Initial version of pcrd, the PCR1000 control daemon / command line interface. This software was developed to provide remote control of the ICOM PCR-1000 radio receiver via serial port and network socket connections.

### Evolution

The project evolved from a simple command-line tool (pcr.c by sili@l0pht.com) into a full-featured daemon mode application with the following major milestones:
1. **v0.01-0.03**: Initial daemon support and signal handling
2. **v0.05**: Improved reporting and uptime tracking
3. **v0.07**: Added timeout protection for communication failures
4. **v0.10**: Performance improvements for GUI interface latency
5. **v0.12**: Modern compiler compatibility updates
6. **v0.13**: Code modernization, cleanup, header file extraction, and documentation updates

### Platform Support

The software supports Linux and FreeBSD with the same POSIX-compliant codebase. No platform-specific build targets are required. Default serial port is `/dev/ttyUSB0`.

### Note from Original Author

From revision 1.14 notes: The author planned to transition from C to C++ with a modular radio class design to support multiple radio types (PCR-1000 and Kenwood TS-440), but this architectural change was never implemented.

---

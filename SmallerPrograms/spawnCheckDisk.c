/**
 * @file spawnCheckDisk.c
 * @author Braiden Gole
 * @brief Not for executing just a information sample.
 * --------------------------------------------------------------------------
 * [SOURCE/BOOK]: AL KELLY, IRA POHL ["A Book on C"] Fourth edition page 560.
 * --------------------------------------------------------------------------
 *        This sample is about spawning processing in the (C)
 *        programming language this has support for MSDOS.
 *        We are not going to use the functions "fork()" or "execl()"
 *        because they are part of the UNIX operating system and MSDOS is
 *        not a multithreaded architecture unlike UNIX. A solution to this is
 *        to use "spawnl()" in (C) for Windows MSDOS in combination with
 *        "popen()" in the (C) programming language to get around this.
 * 
 * NOTE: I have been wondering about this topic for a long time as I have
 *       wanted to do a process in a batch script which involved performing a
 *       automated chkdsk operation given specific parameters. I realized slowly you
 *       cant keep track of the chkdsk prosses, you can launch it but and control it from the
 *       secondary window in a batch process, yet the output of the other process.
 * 
 *       Well while reading a "Book on C" I came across the spawning functions
 *       for MSDOS and it actually involved a chkdsk operation.
 * 
 *       The solution to my problem would be to call a (C) program from
 *       a batch script and use spawnl to call the process and then to get
 *       any output from the other process I would have to use "popen()".
 * 
 *  This is a small sample of spawning process in MSDOS.
 * --------------------------------------------------------------------------
 * @version 0.1
 * @date 2021-01-07
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>
#include <process.h>

int main(void)
{   
    // We have pre-defined macros in "process.h." that handle different situations.
    
    // Use different modes for different situations kind of like the one I mentioned in
    // the header comment above.
    const int KMODE = P_DETACH;
    const char* KEXEOP = "C:\\Windows\\System32\\chkdsk.exe";
    const char* KOPERATION = "chkdsk";
    const char* KDRIVELETTER = "c:";
    const char* KPARAMETERS = "/f";
    const char* KENDARG = 0;

    // We can use "spawnl" in combination with "popen()" to handle output.
    intptr_t retValue = spawnl(KMODE, KEXEOP, KOPERATION, 
                               KDRIVELETTER, KPARAMETERS, KENDARG);

    printf("%i ", retValue);
    return 0;
}

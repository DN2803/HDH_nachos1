// exception.cc 
//	Entry point into the Nachos kernel from user programs.
//	There are two kinds of things that can cause control to
//	transfer back to here from user code:
//
//	syscall -- The user code explicitly requests to call a procedure
//	in the Nachos kernel.  Right now, the only function we support is
//	"Halt".
//
//	exceptions -- The user code does something that the CPU can't handle.
//	For instance, accessing memory that doesn't exist, arithmetic errors,
//	etc.  
//
//	Interrupts (which can also cause control to transfer from user
//	code into the Nachos kernel) are handled elsewhere.
//
// For now, this only handles the Halt() system call.
// Everything else core dumps.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"
#include "syscall.h"
//----------------------------------------------------------------------
// ExceptionHandler
// 	Entry point into the Nachos kernel.  Called when a user program
//	is executing, and either does a syscall, or generates an addressing
//	or arithmetic exception.
//
// 	For system calls, the following is the calling convention:
//
// 	system call code -- r2
//		arg1 -- r4
//		arg2 -- r5
//		arg3 -- r6
//		arg4 -- r7
//
//	The result of the system call, if any, must be put back into r2. 
//
// And don't forget to increment the pc before returning. (Or else you'll
// loop making the same system call forever!
//
//	"which" is the kind of exception.  The list of possible exceptions 
//	are in machine.h.
//----------------------------------------------------------------------
void increasePC()
{
    int counter = machine->ReadRegister(PCReg);
   	machine->WriteRegister(PrevPCReg, counter);
    counter = machine->ReadRegister(NextPCReg);
    machine->WriteRegister(PCReg, counter);
   	machine->WriteRegister(NextPCReg, counter + 4);
}
void ExceptionHandler(ExceptionType which)
{
    int type = machine->ReadRegister(2);


    switch (which)
    {
    case NoException:
        return;
    case PageFaultException: 
        DEBUG('a', "\n Shutdown, No valid translation found.");
        printf("\n\nShut down, No valid translation found.");
        interrupt->Halt();
        break;
    case ReadOnlyException:
        DEBUG('a', "\n Shutdown, Write attempted to page marked read-only.");
        printf("\n\nShutdown, Write attempted to page marked read-only.");
        interrupt->Halt();
        break;
    case BusErrorException:
        DEBUG('a', "\n Shutdown, Translation resulted in an invalid physical address.");
        printf("\n\nShut down, Translation resulted in an invalid physical address.");
        interrupt->Halt();
        break;
    case AddressErrorException:
        DEBUG('a', "\n Shutdown, Unaligned reference or one that was beyond the end of the address space.");
        printf("\n\nShut down, Unaligned reference or one that was beyond the end of the address space.");
        interrupt->Halt();
        break;
    case OverflowException:
        DEBUG('a', "\n Shutdown, Integer overflow in add or sub.");
        printf("\n\nShut down, Integer overflow in add or sub.");
        interrupt->Halt();
        break;
    case IllegalInstrException:
        DEBUG('a', "\n Shutdown, Unimplemented or reserved instr..");
        printf("\n\nShut down, Unimplemented or reserved instr..");
        interrupt->Halt();
        break;
    case NumExceptionTypes:
        DEBUG('a', "\n");
        printf("\n\n");
        interrupt->Halt();
        break;
    case SyscallException:
        // cần xử lý nè 
        switch (type)
        {
            case SC_Halt: 
                DEBUG('a', "\n Shutdown, initiated by user program."); 
                printf ("\n\n Shutdown, initiated by user program."); 
                interrupt->Halt(); 
                break; 
        }
        break;
    }
}


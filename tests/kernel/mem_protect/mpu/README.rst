.. _protection_tests:

Protection tests
#################################

Overview
********
This test case verifies that protection is provided
against the following:

* Inheritance of permissions
* Memory domain features.
* k objects validations.

Building and Running
********************

This project can be built and executed as follows:

.. zephyr-app-commands::
   :zephyr-app: tests/kernel/mem_protect/mpu
   :board: qemu_x86
   :goals: run
   :compact:



Sample Output
=============

.. code-block:: console

    
    ***** BOOTING ZEPHYR OS v1.9.99 - BUILD: Nov 29 2017 13:27:32 *****
    Running test suite inherit_test_1
    ===================================================================
    starting test - inherit_test_1
    PASS - inherit_test_1.
    ===================================================================
    starting test - mem_domain_ztest_1
    PASS - mem_domain_ztest_1.
    ===================================================================
    starting test - mem_domain_ztest_2
    ***** CPU Page Fault (error code 0x00000007)
    User thread wrote address 0x00405000
    PDE: 0x027 Present, Writable, User, Execute Enabled
    PTE: 0x80000000263 Present, Writable, Supervisor, Execute Disable
    Current thread ID = 0x00431220
    Faulting segment:address = 0x002b:0x000019c6
    eax: 0x00000001, ebx: 0x00000002, ecx: 0x004213c8, edx: 0x000063ac
    esi: 0x00000000, edi: 0x004213ec, ebp: 0x004213d0, esp: 0x00420ff8
    eflags: 0x297
    Caught system error -- reason 6
    valid_fault ->here
    PASS - mem_domain_ztest_2.
    ===================================================================
    starting test - mem_domain_ztest_3
    PASS - mem_domain_ztest_3.
    ===================================================================
    starting test - mem_domain_ztest_4
    ***** CPU Page Fault (error code 0x00000007)
    User thread wrote address 0x0040b000
    PDE: 0x027 Present, Writable, User, Execute Enabled
    PTE: 0x80000000263 Present, Writable, Supervisor, Execute Disable
    Current thread ID = 0x004312e0
    Faulting segment:address = 0x002b:0x00001acf
    eax: 0x00000003, ebx: 0x00420033, ecx: 0x00000000, edx: 0x00000004
    esi: 0x00000000, edi: 0x004277ec, ebp: 0x004277d0, esp: 0x00426ff8
    eflags: 0x293
    Caught system error -- reason 6
    PASS - mem_domain_ztest_4.
    ===================================================================
    starting test - mem_domain_ztest_5
    ***** CPU Page Fault (error code 0x00000007)
    User thread wrote address 0x00407000
    PDE: 0x027 Present, Writable, User, Execute Enabled
    PTE: 0x80000000263 Present, Writable, Supervisor, Execute Disable
    Current thread ID = 0x004311c0
    Faulting segment:address = 0x002b:0x00001af7
    eax: 0x0000648d, ebx: 0x00410033, ecx: 0x0041e3cc, edx: 0x00006358
    esi: 0x00000000, edi: 0x0041e3ec, ebp: 0x0041e3d0, esp: 0x0041dff8
    eflags: 0x246
    Caught system error -- reason 6
    PASS - mem_domain_ztest_5.
    ===================================================================
    starting test - mem_domain_ztest_6
    mem_domain_for_user_tc6
    ***** CPU Page Fault (error code 0x00000007)
    User thread wrote address 0x00408000
    PDE: 0x027 Present, Writable, User, Execute Enabled
    PTE: 0x80000000263 Present, Writable, Supervisor, Execute Disable
    Current thread ID = 0x004312e0
    Faulting segment:address = 0x002b:0x00001b26
    eax: 0x00000005, ebx: 0x00420033, ecx: 0x004277c8, edx: 0x00006340
    esi: 0x00000000, edi: 0x004277ec, ebp: 0x004277d0, esp: 0x00426ff8
    eflags: 0x246
    Caught system error -- reason 6
    valid_fault ->here
    PASS - mem_domain_ztest_6.
    ===================================================================
    starting test - kobject_test_1
    0x00000000 is not a valid k_sem
    FATAL: syscall _handler_k_sem_take failed check: access denied
    ***** Kernel OOPS! *****
    Current thread ID = 0x004312e0
    Faulting segment:address = 0x002b:0x0000164d
    eax: 0x00000000, ebx: 0x00000000, ecx: 0x00000000, edx: 0x00000000
    esi: 0x00000000, edi: 0x00000000, ebp: 0x00000000, esp: 0x004277cc
    eflags: 0x286
    Caught system error -- reason 7
    valid_fault ->here
    PASS - kobject_test_1.
    ===================================================================
    starting test - kobject_test_2
    0x00431548 is not a valid k_sem
    FATAL: syscall _handler_k_sem_take failed check: access denied
    ***** Kernel OOPS! *****
    Current thread ID = 0x004312e0
    Faulting segment:address = 0x002b:0x0000164d
    eax: 0x00000000, ebx: 0x00000000, ecx: 0x00000000, edx: 0x00000000
    esi: 0x00000000, edi: 0x00000000, ebp: 0x00000000, esp: 0x004277cc
    eflags: 0x286
    Caught system error -- reason 7
    valid_fault ->here
    PASS - kobject_test_2.
    ===================================================================
    starting test - kobject_test_3
    thread 0x004312e0 (7) does not have permission on k_sem 0x00431524 [0000]
    FATAL: syscall _handler_k_sem_give failed check: access denied
    ***** Kernel OOPS! *****
    Current thread ID = 0x004312e0
    Faulting segment:address = 0x002b:0x00001602
    eax: 0x00000000, ebx: 0x00000000, ecx: 0x00000000, edx: 0x00000000
    esi: 0x00000000, edi: 0x00000000, ebp: 0x00000000, esp: 0x004277cc
    eflags: 0x246
    Caught system error -- reason 7
    valid_fault ->here
    PASS - kobject_test_3.
    ===================================================================
    starting test - kobject_test_4
    thread 0x00431160 (1) does not have permission on k_sem 0x00431524 [0000]
    FATAL: syscall _handler_k_sem_give failed check: access denied
    ***** Kernel OOPS! *****
    Current thread ID = 0x00431160
    Faulting segment:address = 0x002b:0x00001602
    eax: 0x00000000, ebx: 0x00000000, ecx: 0x00000000, edx: 0x00000000
    esi: 0x00000000, edi: 0x00000000, ebp: 0x00000000, esp: 0x0041b0cc
    eflags: 0x246
    Caught system error -- reason 7
    valid_fault ->here
    PASS - kobject_test_4.
    ===================================================================
    ===================================================================
PROJECT EXECUTION SUCCESSFUL

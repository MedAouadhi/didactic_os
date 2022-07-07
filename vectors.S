/**
*/

.globl error_handler
error_handler:
	mov x0, #0xA5
	mov x1, #0x5A
loop:
    b loop

.globl irq_handler
irq_handler:
    b .


/*
offset  event type 	                description
------------------------------------------------------------
0x000 	Synchronous Exception 	    EL is using SP_EL0 stack
0x080 	IRQ 	                    EL is using SP_EL0 stack
0x100 	FIQ 	                    EL is using SP_EL0 stack
0x180 	SError 	                    EL is using SP_EL0 stack
------------------------------------------------------------
0x200 	Synchronous Exception 	    EL is using SP_ELx stack
0x280 	IRQ 	                    EL is using SP_ELx stack
0x300 	FIQ 	                    EL is using SP_ELx stack
0x380 	SError 	                    EL is using SP_ELx stack
------------------------------------------------------------
0x400 	Synchronous Exception 	    From lower EL in AArch64
0x480 	IRQ 	                    From lower EL in AArch64
0x500 	FIQ 	                    From lower EL in AArch64
0x580 	SError 	                    From lower EL in AArch64
------------------------------------------------------------
0x600 	Synchronous Exception       From lower EL in AArch32
0x680 	IRQ 	                    From lower EL in AArch32
0x700 	FIQ 	                    From lower EL in AArch32
0x780 	SError 	                    From lower EL in AArch32
*/
.section ".text"
.global vector_table_el2

// Typical exception vector table code.
.balign 0x800
vector_table_el2:
curr_el_sp0_sync: // The exception handler for the synchronous
// exception from the current EL using SP0.
    b error_handler

.balign 0x80
curr_el_sp0_irq: // The exception handler for the IRQ exception
// from the current EL using SP0.
    b error_handler

.balign 0x80
curr_el_sp0_fiq: // The exception handler for the FIQ exception
// from the current EL using SP0.
    b error_handler

.balign 0x80
curr_el_sp0_serror: // The exception handler for the system error
// exception from the current EL using SP0.
    b error_handler

.balign 0x80
curr_el_spx_sync: // The exception handler for the synchronous
// exception from the current EL using the
    b error_handler

// current SP.
.balign 0x80
curr_el_spx_irq: // The exception handler for IRQ exception
// from the current EL using the current SP.
    b irq_handler

.balign 0x80
curr_el_spx_fiq: // The exception handler for the FIQ exception
// from the current EL using the current SP.
    b error_handler

.balign 0x80
curr_el_spx_serror: // The exception handler for the system error
// exception from the current EL using the current SP.
    b error_handler

.balign 0x80
lower_el_aarch64_sync: // The exception handler for the synchronous
// exception from a lower EL (AArch64).
    b error_handler

.balign 0x80
lower_el_aarch64_irq: // The exception handler for the IRQ exception
// from a lower EL (AArch64).
    b error_handler

.balign 0x80
lower_el_aarch64_fiq: // The exception handler for the FIQ exception
// from a lower EL (AArch64).
.balign 0x80
lower_el_aarch64_serror: // The exception handler for the system error
// exception from a lower EL(AArch64).
    b error_handler

.balign 0x80
lower_el_aarch32_sync: // The exception handler for the synchronous
// exception from a lower EL(AArch32).
    b error_handler

.balign 0x80
lower_el_aarch32_irq: // The exception handler for the IRQ exception
// from a lower EL (AArch32).
    b error_handler

.balign 0x80
lower_el_aarch32_fiq: // The exception handler for the FIQ exception
// from a lower EL (AArch32).
    b error_handler

.balign 0x80
lower_el_aarch32_serror: // The exception handler for the system error
// exception from a lower EL(AArch32).
    b error_handler

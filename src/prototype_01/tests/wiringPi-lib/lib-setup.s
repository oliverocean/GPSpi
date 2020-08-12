/**
 * @author: Oliver Ocean <github@oliverocean.co>
 * @compile: gcc -o foo foo.s -lwiringPi -lcrypt -lpthread -lm -lrt 
 */

/* ---------------[ Text ]--------------- */
		.text
		.global main

main:
	adr x0, msg_intro
	bl printf

	// initialize wiringPi
	bl wiringPiSetup    

	// set TXD pinMode (OUTPUT)
	adr x0, msg_set_mode
	bl printf
	adr x0, gpio_pin_txd
	ldr x0, [x0]
	adr x1, gpio_mode_output
	ldr x1, [x1]
	bl pinMode          

	// set RXD pinMode (INPUT)
	adr x0, msg_set_mode
	bl printf
	adr x0, gpio_pin_rxd
	ldr x0, [x0]
	adr x1, gpio_mode_input
	ldr x1, [x1]
	bl pinMode          

	// open TXD port
	adr x0, msg_port_open
	bl printf
	adr x0, gpio_pin_txd
	ldr w0, [x0]
	adr x1, set_high
	ldr w1, [x1]

	// open RXD port
	adr x0, msg_port_open
	bl printf
	adr x0, gpio_pin_rxd
	ldr w0, [x0]
	adr x1, set_high
	ldr w1, [x1]
 
 	// read serial data, print out
	// @to-do

	// close TXD port
	adr x0, msg_port_close
	bl printf
	adr x0, gpio_pin_txd
	ldr w0, [x0]
	adr x1, set_low
	ldr w1, [x1]
	bl digitalWrite

	// close RXD port
	adr x0, msg_port_close
	bl printf
	adr x0, gpio_pin_rxd
	ldr w0, [x0]
	adr x1, set_low
	ldr w1, [x1]
	bl digitalWrite // digitalWrite(pin, value)

	// exit
	adr x0, msg_exit
	bl printf
	mov x8, 93
	svc 0


/* ---------------[ Data ]--------------- */
		  .data

msg_intro:	  .asciz "> starting...\n"
msg_set_mode:	  .asciz "> pinMode: setting\n"
msg_port_open:	  .asciz "> port: opening\n"
msg_read_data:	  .asciz "> reading data...\n"
msg_output_data:  .asciz "> the data output:\n%d\n"
msg_port_close:   .asciz "> port: closing\n"
msg_exit:	  .asciz "> exiting...\n"

gpio_pin_txd:	  .int   14
gpio_pin_rxd:	  .int   15

gpio_mode_input:  .asciz "INPUT"
gpio_mode_output: .asciz "OUTPUT"

set_low:	  .int   0
set_high:	  .int   1

time_delay:	  .int   1000 // milliseconds

//input_format:      .string "%8s" // limit to 1 char

/* ---------------[ EOF ]--------------- */
		.end

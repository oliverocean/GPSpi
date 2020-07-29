/* *
 * @author: Oliver Ocean <github@oliverocean.co>
 * @file: led.s
 *
 */

/* ---------------[ Text ]--------------- */
		.text
		.global main

main:
	adr x0, msg_intro
	bl printf

	// initialize wiringPi
	bl wiringPiSetup    

	// pinMode(pin, mode)
	mov x0, gpio_pin
	mov x1, gpio_mode
	bl pinMode          

	// initialize while_loop 
	mov x19, xzr         // loop counter
	mov x20, 4   	    // max loops
	b while_loop

	b exit

while_loop:
	// compare to max
	cmp x19, x20          
	bge exit_msg

	// turn led on and pause
	//adr x0, msg_led_on
	//bl printf
	adr x0, gpio_pin
	ldr w0, [x0]
	adr x1, set_high
	ldr w1, [x1]
	bl digitalWrite     // digitalWrite(pin, value)
	adr x0, time_delay  
	ldr w0, [x0]
	bl delay	    // delay(length)

	// turn led off and pause
	//adr x0, msg_led_off
	//bl printf
	adr x0, gpio_pin
	ldr w0, [x0]
	adr x1, set_low
	ldr w1, [x1]
	bl digitalWrite     // digitalWrite(pin, value)
	adr x0, time_delay  
	ldr w0, [x0]
	bl delay	    // delay(length)

	// increment counter and loop
	add x19, x19, 1 	    
	b while_loop

exit_msg:
	adr x0, msg_exit
	bl printf

exit:
	mov x8, 93
	svc 0

/* ---------------[ Data ]--------------- */
		.data

msg_intro:	.asciz "> starting...\n"
msg_led_on:	.asciz "> led: on\n"
msg_led_off:	.asciz "> led: off\n"
msg_exit:	.asciz "> exiting...\n"

gpio_pin:	.int   0    // pin  = 0 (wiringPi.h map)
gpio_mode:	.int   1    // mode = OUTPUT 

set_high:	.int   1
set_low:	.int   0

time_delay:	.int   1000 // milliseconds

/* ---------------[ EOF ]--------------- */
		.end

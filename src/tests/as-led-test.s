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
	mov x2, xzr         // loop counter
	mov x3, 4   	    // max loops
	b while_loop

	b exit

while_loop:
	// compare to max
	cmp x2, x3          
	bge exit_msg

	// turn led on and pause
	adr x0, msg_led_on
	bl printf
	mov x0, gpio_pin
	mov x1, set_high
	bl digitalWrite     // digitalWrite(pin, value)
	mov x0, time_delay  
	bl delay	    // delay(length)

	// turn led off and pause
	mov x0, msg_led_off
	bl printf
	mov x0, gpio_pin
	mov x1, set_low
	bl digitalWrite     // digitalWrite(pin, value)
	mov x0, time_delay  
	bl delay	    // delay(length)

	// increment counter and loop
	add x2, x2, 1 	    
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

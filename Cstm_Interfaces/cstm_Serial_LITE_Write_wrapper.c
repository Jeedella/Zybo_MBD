
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>

#ifndef MATLAB_MEX_FILE
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <fcntl.h> // Contains file controls like O_RDWR
#include <errno.h> // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h> // write(), read(), close()
#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Start function
 *
 */
void cstm_Serial_LITE_Write_Start_wrapper(const uint32_T *Port, const int_T p_width0)
{
/* %%%-SFUNWIZ_wrapper_Start_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE
unsigned char PortLocation[25];
sprintf(PortLocation,"/dev/ttyUL%d",Port[0]);
int temp = 0;
int serial_port = open(PortLocation, O_RDWR | O_NDELAY | O_NONBLOCK);

// Create new termios struc, called'tty' for convention
struct termios tty;
memset(&tty, 0, sizeof tty);

if(serial_port < 0){
    //error
    temp = errno;
} else {
    // Create new termios struc, we call it 'tty' for convention
    struct termios tty;
    memset(&tty, 0, sizeof tty);

    // Read in existing settings, and handle any error
    if(tcgetattr(serial_port, &tty) != 0) {
        //error
        temp = errno;
    } else {
        tty.c_oflag &= ~ICANON;
        tty.c_lflag &= ~ECHO; // disable echo
        tty.c_lflag &= ~ECHOE; // disable erasure
        tty.c_lflag &= ~ECHONL; // disable new-line echo
        tty.c_cflag |= CREAD | CLOCAL; // Turn on READ & ignore ctrl lines (CLOCAL = 1)
        tty.c_lflag &= ~ISIG; // Disable interpretation of INTR, QUIT and SUSP
        tty.c_iflag &= ~(IXON | IXOFF | IXANY); // Turn off s/w flow ctrl
        tty.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL); // Disable any special handling of received bytes
        tty.c_oflag &= ~OPOST; // Prevent special interpretation of output bytes (e.g. newline chars)
        tty.c_oflag &= ~ONLCR; // Prevent conversion of newline to carriage return/line feed
        
        // save tty settings, also checking for error
        if(tcsetattr(serial_port, TCSANOW, &tty) != 0){
            //error
            temp = errno;
		}
	}
}

#endif
/* %%%-SFUNWIZ_wrapper_Start_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Output function
 *
 */
void cstm_Serial_LITE_Write_Outputs_wrapper(const uint8_T *Data,
			const uint32_T *Port, const int_T p_width0,
			const int_T u_width)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE
unsigned char PortLocation[25];
sprintf(PortLocation,"/dev/ttyUL%d",Port[0]);
int serial_port = open(PortLocation, O_RDWR | O_NDELAY | O_NONBLOCK);
int msgSize = 0;
int temp = 0;

if(serial_port < 0){
    //error
    temp = errno;
} else {
    write(serial_port, Data, u_width);
    close(serial_port);
}
#endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}




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
 * Output function
 *
 */
void cstm_Serial_16550_Write____Outputs_wrapper(const uint8_T *Data,
			const uint32_T *Port, const int_T p_width0,
			const uint32_T *BaudRate, const int_T p_width1,
			const uint32_T *Parity, const int_T p_width2,
			const uint32_T *StopBits, const int_T p_width3,
			const int_T u_width)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE
unsigned char PortLocation[25];
sprintf(PortLocation,"/dev/ttyS%d",Port[0]);
int serial_port = open(PortLocation, O_RDWR);
int msgSize = 0;
int temp = 0;
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
        if(Parity[0] == 0) tty.c_cflag &= ~PARENB; // clear parity bit, disabling parity
        else tty.c_cflag |= PARENB; // set parity bit, enable parity
        if(Parity[0] == 1) tty.c_cflag &= ~PARODD; // clear odd parity bit, even parity
        else if(Parity[0] == 2) tty.c_cflag |= PARODD; // set odd parity bit, odd parity
        
        if(StopBits == 1) tty.c_cflag &= ~CSTOPB; // clear stop field, one stop bit used
        else tty.c_cflag &= ~CSTOPB; // set stop field, two stop bits used
        
        tty.c_cflag |= CS8; // 8 bits per byte
        tty.c_cflag &= ~CRTSCTS; // disable RTS/CTS hardware flow control
        tty.c_cflag |= CREAD | CLOCAL; // turn on READ & ignore ctrl lines (CLOCAL = 1)

        tty.c_lflag &= ~ICANON;
        tty.c_lflag &= ~ECHO; // disable echo
        tty.c_lflag &= ~ECHOE; // disable erasure
        tty.c_lflag &= ~ECHONL; // disable new-line echo
        tty.c_lflag &= ~ISIG; // disable interpretation of INTR, QUIT and SUSP
        tty.c_iflag &= ~(IXON | IXOFF | IXANY); // turn off s/w flow ctrl
        tty.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL); // disable any special handling of received bytes

        tty.c_oflag &= ~OPOST; // prevent special interpretation of output bytes (e.g. newline chars)
        tty.c_oflag &= ~ONLCR; // prevent conversion of newline to carriage return/line feed

        tty.c_cc[VTIME] = 1;    // wait for up to 1s (10 deciseconds), returning as soon as any data is received.
        tty.c_cc[VMIN] = 0;

        // set input baud rate
        cfsetospeed(&tty, BaudRate[0]);
        
        // save tty settings, also checking for error
        if(tcsetattr(serial_port, TCSANOW, &tty) != 0){
            //error
            temp = errno;
        } else {
			write(serial_port, Data, u_width);
		}
    }
    close(serial_port);
}
#endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}



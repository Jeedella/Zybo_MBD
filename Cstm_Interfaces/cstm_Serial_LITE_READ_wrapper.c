
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
#include <string.h>
#include <unistd.h>  
#include <fcntl.h>   
#include <errno.h>   
#include <termios.h> 
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/ioctl.h>
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
void cstm_Serial_LITE_READ_Start_wrapper(const uint32_T *Port, const int_T p_width0,
			const uint32_T *DataLength, const int_T p_width1)
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
void cstm_Serial_LITE_READ_Outputs_wrapper(uint8_T *Data,
			uint8_T *Status,
			const uint32_T *Port, const int_T p_width0,
			const uint32_T *DataLength, const int_T p_width1,
			const int_T y_width)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE
unsigned char PortLocation[25];
sprintf(PortLocation,"/dev/ttyUL%d",Port[0]);
int serial_port = open(PortLocation, O_RDWR | O_NOCTTY | O_NDELAY | O_NONBLOCK);
int msgSize = 0;
int temp = 0;

static char Buffer[256];
static char ByteToRead[1];
static char CurrentByte = 0;
static int bytes_available = 0;

if(serial_port < 0){
    //error
    Status[0] = errno;
} else {
    if (ioctl(serial_port, FIONREAD, &bytes_available) < 0){
        Status[0] = errno;
        bytes_available = DataLength[0];
    } else if(bytes_available > 0){
        msgSize = read(serial_port, ByteToRead, 1);
        Buffer[CurrentByte] = ByteToRead[0];
        if(++CurrentByte >= DataLength[0]){
            CurrentByte = 0;
            for(int i = 0; i < DataLength[0]; i++){
                Data[i] = Buffer[i];
            }
        }
        Status[0] = CurrentByte;
    }
    close(serial_port);
}
#endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}



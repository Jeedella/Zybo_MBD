
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
 
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Start function
 *
 */
void cstm_Serial_16550_READ_Start_wrapper(const uint32_T *Port, const int_T p_width0,
			const uint32_T *BaudRate, const int_T p_width1,
			const uint32_T *Parity, const int_T p_width2,
			const uint32_T *StopBits, const int_T p_width3,
			const uint32_T *DataLength, const int_T p_width4)
{
/* %%%-SFUNWIZ_wrapper_Start_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE
unsigned char PortLocation[25];
sprintf(PortLocation,"/dev/ttyS%d",Port[0]);
int temp = 0;
int Baud = 0;
int AsciiNumConst = 48;
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

        tty.c_cc[VTIME] = 0;    // wait for up to 1s (10 deciseconds), returning as soon as any data is received.
        tty.c_cc[VMIN] = 0;
        
        // set baud rate
        int BaudZero = BaudRate[0] - AsciiNumConst;
        int BaudOne = BaudRate[1] - AsciiNumConst;
        int BaudTwo = BaudRate[2] - AsciiNumConst;
        switch(BaudZero){
            case 0:
                Baud = 0;
                break;
            case 1:
                switch(BaudOne){
                    case 1:
                        if(BaudTwo == 0) Baud = 110;
                        else Baud = 115200;
                        break;
                    case 2:
                        Baud = 1200;
                        break;
                    case 3:
                        Baud = 134;
                        break;
                    case 5:
                        Baud = 150;
                        break;
                    case 8:
                        Baud = 1800;
                        break;
                    case 9:
                        Baud = 19200;
                        break;
                    default:
                        Baud = 115200;
                        break;
                }
                break;
            case 2:
                if(BaudOne == 0) Baud = 200;
                else if(BaudOne == 3) Baud = 230400;
                else if(BaudOne == 4) Baud = 2400;
                else Baud = 115200;
                break;
            case 3:
                if(BaudOne == 0) Baud = 300;
                else if(BaudOne == 8) Baud = 38400;
                else Baud = 115200;
                break;
            case 4:
                Baud = 4800;
                break;
            case 5:
                if(BaudOne == 0) Baud = 50;
                else if(BaudOne == 7) Baud = 57600;
                else Baud = 115200;
                break;
            case 6:
                Baud = 600;
                break;
            case 7:
                Baud = 75;
                break;
            case 9:
                Baud = 9600;
                break;
            default:
                Baud = 115200;
                break;
        }
        cfsetspeed(&tty, Baud);
        
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
void cstm_Serial_16550_READ_Outputs_wrapper(uint32_T *Data,
			uint32_T *Status,
			const uint32_T *Port, const int_T p_width0,
			const uint32_T *BaudRate, const int_T p_width1,
			const uint32_T *Parity, const int_T p_width2,
			const uint32_T *StopBits, const int_T p_width3,
			const uint32_T *DataLength, const int_T p_width4,
			const int_T y_width)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE
unsigned char PortLocation[25];
sprintf(PortLocation,"/dev/ttyS%d",Port[0]);
int serial_port = open(PortLocation, O_RDWR | O_NDELAY | O_NONBLOCK);
int msgSize = 0;
int temp = 0;

static char Buffer[256];
static char ByteToRead[1];
static char CurrentByte = 0;
int bytes_available = 0;

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



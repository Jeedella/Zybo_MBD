
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

#include <linux/spi/spidev.h>
#include <sys/ioctl.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>

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
void cstm_SPI_READ_Start_wrapper(const uint32_T *SPI_Device, const int_T p_width0,
			const uint32_T *SPI_SS, const int_T p_width1,
			const int32_T *REGISTER, const int_T p_width2,
			const int32_T *MODE, const int_T p_width3,
			const uint32_T *DATALENGTH, const int_T p_width4)
{
/* %%%-SFUNWIZ_wrapper_Start_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE

char device[25];
sprintf(device, "/dev/spidev%d.%d", SPI_Device[0], SPI_SS[0]);
uint32_t mode;
static uint8_t bits = 8;
static uint32_t speed = 8000000;
int fd;
unsigned long timeOut = 0;
unsigned long timeOutMax = 1000000;

mode = 0;
switch(MODE[0]){
    case 0:
        break;
    case 1:
        mode |= SPI_CPHA;
        break;
    case 2:
        mode |= SPI_CPOL;
        break;
    case 3:
        mode |= SPI_CPHA;
        mode |= SPI_CPOL;
        break;
    default:
        
        break;
}

while(timeOut < timeOutMax){
    fd = open(device, O_RDWR);
    if(fd >= 0) timeOut = timeOutMax;
    timeOut++;
}

ioctl(fd, SPI_IOC_WR_MODE, &mode);
ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &bits);
ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);

close(fd);

#endif
/* %%%-SFUNWIZ_wrapper_Start_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Output function
 *
 */
void cstm_SPI_READ_Outputs_wrapper(uint8_T *OutputByte,
			const uint32_T *SPI_Device, const int_T p_width0,
			const uint32_T *SPI_SS, const int_T p_width1,
			const int32_T *REGISTER, const int_T p_width2,
			const int32_T *MODE, const int_T p_width3,
			const uint32_T *DATALENGTH, const int_T p_width4,
			const int_T y_width)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE

char device[25];
sprintf(device, "/dev/spidev%d.%d", SPI_Device[0], SPI_SS[0]);
int fd;
unsigned long timeOut = 0;
unsigned long timeOutMax = 1000000;
unsigned int sendBuf[(int)(DATALENGTH+1)];
unsigned char recBuf[(int)(DATALENGTH+1)];
uint32_t mode;
static uint16_t delay;
static uint32_t speed = 8000000;
static uint8_t bits = 8;
uint32_t length;

if(REGISTER[0] < 0){
    length = DATALENGTH[0];
    for(uint32_t i = 0; i < DATALENGTH[0]; i++){
        sendBuf[i] = 0;
    }
}else{
    length = DATALENGTH[0] + 1;
    sendBuf[0] = REGISTER[0];
    for(uint32_t i = 0; i < DATALENGTH[0]; i++){
        sendBuf[(i+1)] = 0;
    }
}

struct spi_ioc_transfer SPIDevice = {
    .tx_buf = (unsigned long)sendBuf,
    .rx_buf = (unsigned long)recBuf,
    .len = length,
    .delay_usecs = delay,
    .speed_hz = speed,
    .bits_per_word = bits,
};

while(timeOut < timeOutMax){
    fd = open(device, O_RDWR);
    if(fd >= 0) timeOut = timeOutMax;
    timeOut++;
}

ioctl(fd, SPI_IOC_MESSAGE(1), &SPIDevice);

if(REGISTER[0] < 0){
    for(uint32_t i = 0; i < DATALENGTH[0]; i++){
        OutputByte[i] = recBuf[i];
    }
}else{
    for(uint32_t i = 0; i < DATALENGTH[0]; i++){
        OutputByte[i] = recBuf[(i+1)];
    }
}

close(fd);

#endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}



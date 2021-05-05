
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
#include <linux/i2c-dev.h>
#include <linux/i2c.h>
#include <linux/ioctl.h>
#include <sys/ioctl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/types.h>
#include <string.h>
#include <errno.h>
#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define y_width 1

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
void cstm_I2C_WRITE_Outputs_wrapper(const uint8_T *InputMessage,
			int32_T *ErrorStatus,
			const uint8_T *addr, const int_T p_width0,
			const uint8_T *adapter_nr, const int_T p_width1,
			const uint8_T *byte_order, const int_T p_width2,
			const uint8_T *send_register, const int_T p_width3,
			const uint8_T *slave_register, const int_T p_width4,
			const uint8_T *send_nack, const int_T p_width5,
			const uint8_T *remove_stop, const int_T p_width6,
			const int_T u_width)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE
int file;
//int adapter_nr = 0; /*probably dynamically determined */
char filename[20];
char buffer[(u_width+1)];
int setFlag[] = {0};
int ret = 0;
int tmo = 100;
uint32_t length = 0;

ErrorStatus[0] = 0;
sprintf(filename, "/dev/i2c-%d", adapter_nr[0]);
file = open(filename, O_RDWR);
if(file < 0){
    ErrorStatus[0] = errno;
}
else{
    ret = ioctl(file, I2C_SLAVE, addr[0]);
    if(ret == -1){
        ErrorStatus[0] = errno;
    } else {
        ret = ioctl(file, I2C_TIMEOUT, tmo);
        if(ret == -1){
            ErrorStatus[0] = errno;
        } else {            
            if(remove_stop[0] == 1){
                setFlag[0] &= ~I2C_M_STOP;
            } else{
                setFlag[0] |= I2C_M_STOP;
            }
            
            if(send_nack[0] == 1){
                //setFlag &= ~; what do I even do here
            } else{
                //setFlag |= ; what do I even do here
            }
            
            if(send_register[0] == 1){
                buffer[0] = slave_register[0];
                length = u_width + 1;
                if(byte_order[0] == 1){
                    //little endian
                    for(uint32_t i = 0; i < u_width; i++){
                        buffer[(i+1)] = InputMessage[(u_width - i - 1)];
                    }
                } else {
                    //big endian
                    for(uint32_t i = 0; i < u_width; i++){
                        buffer[(i+1)] = InputMessage[i];
                    }
                }
            }else{
                length = u_width;
                if(byte_order[0] == 1){
                    //little endian
                    for(uint32_t i = 0; i < u_width; i++){
                        buffer[(i)] = InputMessage[(u_width - i - 1)];
                    }
                } else {
                    //big endian
                    for(uint32_t i = 0; i < u_width; i++){
                        buffer[(i)] = InputMessage[i];
                    }
                }
            }
            
            struct i2c_msg msg[1];
            msg[0].addr = addr[0];
            msg[0].flags = setFlag[0];
            msg[0].len = length;
            msg[0].buf = buffer;

            struct i2c_rdwr_ioctl_data i2cMsg;
            i2cMsg.msgs = msg;
            i2cMsg.nmsgs = 1;

            ret = ioctl(file, I2C_RDWR, &i2cMsg);
            if(ret == -1){
                ErrorStatus[0] = errno;
            }
        }
    }
    close(file);
}
#endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}




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
void cstm_I2C_READ_Outputs_wrapper(uint8_T *OutputMessage,
			int32_T *ErrorStatus,
			const uint8_T *addr, const int_T p_width0,
			const uint8_T *adapter_nr, const int_T p_width1,
			const uint8_T *byte_order, const int_T p_width2,
			const uint8_T *message_size, const int_T p_width3,
			const uint8_T *send_register, const int_T p_width4,
			const uint8_T *slave_register, const int_T p_width5,
			const uint8_T *send_nack, const int_T p_width6,
			const uint8_T *remove_stop, const int_T p_width7,
			const int_T y_width)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE
int file;
//int adapter_nr = 0; /*probably dynamically determined */
char filename[20];
char buffer[message_size[0]];
int setFlag[] = {0};
int ret = 0;
int tmo = 100;

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
            setFlag[0] |= I2C_M_RD;
			
            if(send_register[0] == 1){
                //slave register
                setFlag[0] |= I2C_M_NOSTART;
                
                struct i2c_msg msg[2];
                
                msg[0].addr = addr[0];
                msg[0].flags = 0;
                msg[0].len = 1;
                msg[0].buf = slave_register;
                
                msg[1].addr = addr[0];
                msg[1].flags = setFlag[0];
                msg[1].len = message_size[0];
                msg[1].buf = buffer;

                struct i2c_rdwr_ioctl_data i2cMsg;
                i2cMsg.msgs = msg;
                i2cMsg.nmsgs = 2;

                ret = ioctl(file, I2C_RDWR, &i2cMsg);
                if(ret == -1){
                    ErrorStatus[0] = errno;
                }
            }else{
                //no slave register
                
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
                
                struct i2c_msg msg[1];
                
                msg[0].addr = addr[0];
                msg[0].flags = setFlag[0];
                msg[0].len = message_size[0];
                msg[0].buf = buffer;

                struct i2c_rdwr_ioctl_data i2cMsg;
                i2cMsg.msgs = msg;
                i2cMsg.nmsgs = 1;

                ret = ioctl(file, I2C_RDWR, &i2cMsg);
                if(ret == -1){
                    ErrorStatus[0] = errno;
                }
            }
            
            if(byte_order[0] == 1){
                //little endian
                for(uint32_t i = 0; i < message_size[0]; i++){
                    OutputMessage[i] = buffer[(message_size[0] - i - 1)];
                }
            } else {
                //big endian
                for(uint32_t i = 0; i < message_size[0]; i++){
                    OutputMessage[i] = buffer[i];
                }
            }
        }
    }
    close(file);
}
#endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}



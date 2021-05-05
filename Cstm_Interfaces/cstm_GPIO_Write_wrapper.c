
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

#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/ioctl.h>
#include <fcntl.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <linux/types.h>

#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1

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
void cstm_GPIO_Write_Start_wrapper(const uint32_T *GPIOport, const int_T p_width0)
{
/* %%%-SFUNWIZ_wrapper_Start_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE 

int32_t efd, ret;
char bufGPIOpath[50];
char bufGPIOnum[10];

//gpio_open
sprintf(bufGPIOnum, "%d", GPIOport[0]);

efd = open("/sys/class/gpio/export", O_WRONLY);

if(efd != -1){
    ret = write(efd, bufGPIOnum, strlen(bufGPIOnum));

    if(ret < 0) {
        printf("could not export gpio, return value: %d\r\n", ret);
        printf("tried gpio %d\r\n", GPIOport[0]);
        return -2;
    }
}else{
    printf("could not open export file, return value: %d\r\n", efd);
    printf("tried gpio %d\r\n", GPIOport[0]);
    return -1;
}

close(efd);
printf("export succes: %d\r\n", GPIOport[0]);

//gpio_setdir
sprintf(bufGPIOpath, "/sys/class/gpio/gpio%d/direction", GPIOport[0]);
efd = open(bufGPIOpath, O_WRONLY);

if(efd != -1){
    ret = write(efd, "out", strlen("out"));

    if(ret < 0) {
        printf("could not set direction, return value: %d\r\n", ret);
        printf("tried gpio %d\r\n", GPIOport[0]);
        return -6;
    }
}else{
    printf("could not open direction file, return value: %d\r\n", efd);
    printf("tried gpio %d\r\n", GPIOport[0]);
    return -5;
}

close(efd);
printf("direction has been set\r\n");

//gpio_setval
char valueBuf[1];
sprintf(valueBuf, "%d", 0);
sprintf(bufGPIOpath, "/sys/class/gpio/gpio%d/value", GPIOport[0]);
efd = open(bufGPIOpath, O_WRONLY);

if(efd != -1){

    ret = write(efd, valueBuf, strlen(valueBuf));
    if(ret < 0) {
        printf("could not set value %d, return value: %d\r\n", 0, ret);
        printf("tried gpio %d\r\n", GPIOport[0]);
        return -8;
    }
}else{
    printf("could not open value file, return value: %d\r\n", efd);
    printf("tried gpio %d\r\n", GPIOport[0]);
    return -7;
}

close(efd);

printf("write succes @ port: %d\r\n", GPIOport[0]);
#endif
/* %%%-SFUNWIZ_wrapper_Start_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Output function
 *
 */
void cstm_GPIO_Write_Outputs_wrapper(const boolean_T *Val,
			const uint32_T *GPIOport, const int_T p_width0)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE 

int32_t efd, ret;
char bufGPIOpath[50];

//gpio_setval
char valueBuf[1];
sprintf(valueBuf, "%d", (uint8_t)Val[0]);
sprintf(bufGPIOpath, "/sys/class/gpio/gpio%d/value", GPIOport[0]);
efd = open(bufGPIOpath, O_WRONLY);

if(efd != -1){

    ret = write(efd, valueBuf, strlen(valueBuf));
    if(ret < 0) {
        printf("could not set value %d, return value: %d\r\n", Val[0], ret);
        printf("tried gpio %d\r\n", GPIOport[0]);
        return -8;
    }
}else{
    printf("could not open value file, return value: %d\r\n", efd);
    printf("tried gpio %d\r\n", GPIOport[0]);
    return -7;
}

close(efd);

printf("write succes @ port: %d\r\n", GPIOport[0]);
#endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Terminate function
 *
 */
void cstm_GPIO_Write_Terminate_wrapper(const uint32_T *GPIOport, const int_T p_width0)
{
/* %%%-SFUNWIZ_wrapper_Terminate_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE 

int32_t efd, ret;
char bufGPIOpath[50];
char bufGPIOnum[10];

//gpio_close
sprintf(bufGPIOnum, "%d", GPIOport[0]);
efd = open("/sys/class/gpio/unexport", O_WRONLY);

if(efd != -1){
    ret = write(efd, bufGPIOnum, strlen(bufGPIOnum));

    if(ret < 0){
        printf("could not unexport gpio, return value: %d\r\n", ret);
        printf("tried gpio %d\r\n", GPIOport[0]);
        return -4;
    }
} else {
    printf("could not open unexport file, return value: %d\r\n", efd);
    printf("tried gpio %d\r\n", GPIOport[0]);
    return -3;
}

close(efd);

printf("unexport succes\r\n");
#endif
/* %%%-SFUNWIZ_wrapper_Terminate_Changes_END --- EDIT HERE TO _BEGIN */
}


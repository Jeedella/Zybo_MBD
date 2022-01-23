
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
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#define MAP_SIZE 4096UL
#define MAP_MASK (MAP_SIZE -1)

unsigned int value;

int*  modulator;
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
void zybo_pwm_Start_wrapper(real_T *xD,
			const uint32_T *PWM_BASE_ADDR, const int_T p_width0,
			const uint32_T *PWM_PERIOD, const int_T p_width1,
			const uint32_T *DUTY_LOWER_LIMIT, const int_T p_width2,
			const uint8_T *MOTOR_DIR_DECODING, const int_T p_width3)
{
/* %%%-SFUNWIZ_wrapper_Start_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Custom Start code goes here.
 */
#ifndef MATLAB_MEX_FILE
//this function gets physical address of the memory and
//gives virtual address which is understandable for the OS
//through this function we can have directly access to the memory without needing the device drive
void* getVirtualAddress(int phys_addr)  {
    void* mapped_base;
    int memfd;
    void* mapped_dev_base;
    off_t dev_base = phys_addr;
    memfd = open("/dev/mem", O_RDWR | O_SYNC);
    if (memfd ==  -1) {
        printf("can't open /dev/mem\n");
        exit(0);
    }
    mapped_base = mmap(0, MAP_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, memfd, dev_base & ~MAP_MASK);
    if(mapped_base == (void*) -1) {
        printf("can't map the memory to user space.\n");
        exit(0);
    }
    mapped_dev_base =  mapped_base + (dev_base & MAP_MASK);
    return mapped_dev_base;
}
modulator = getVirtualAddress(*PWM_BASE_ADDR);
 // set the PWM period 
//  pW[0]
*((unsigned *) (modulator + 2)) = 0x0; // Disable Motor
*((unsigned *) (modulator  + 0))= *PWM_PERIOD;  /* 110592; */
*((unsigned *) (modulator  + 1))= (*PWM_PERIOD)/2;  

#endif
/* %%%-SFUNWIZ_wrapper_Start_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Output function
 *
 */
void zybo_pwm_Outputs_wrapper(const real_T *Duty,
			const real_T *En,
			const real_T *xD,
			const uint32_T *PWM_BASE_ADDR, const int_T p_width0,
			const uint32_T *PWM_PERIOD, const int_T p_width1,
			const uint32_T *DUTY_LOWER_LIMIT, const int_T p_width2,
			const uint8_T *MOTOR_DIR_DECODING, const int_T p_width3)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/* This sample sets the output equal to the input
      y0[0] = u0[0]; 
 For complex signals use: y0[0].re = u0[0].re; 
      y0[0].im = u0[0].im;
      y1[0].re = u1[0].re;
      y1[0].im = u1[0].im;
 */
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Updates function
 *
 */
void zybo_pwm_Update_wrapper(const real_T *Duty,
			const real_T *En,
			real_T *xD,
			const uint32_T *PWM_BASE_ADDR, const int_T p_width0,
			const uint32_T *PWM_PERIOD, const int_T p_width1,
			const uint32_T *DUTY_LOWER_LIMIT, const int_T p_width2,
			const uint8_T *MOTOR_DIR_DECODING, const int_T p_width3)
{
/* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Code example
 *   xD[0] = u0[0];
 */
#ifndef MATLAB_MEX_FILE
// Enable motor CW > 0x3; CCW -> 0x1
if((Duty[0] >=100 ) || (Duty[0] <= 0 )) {
        printf("Duty cycle is outside of the allowed range.\n");
        exit(0);
}
if(En[0])
{
    if(*MOTOR_DIR_DECODING )
    {
        if (Duty[0] >= 50)
        {
            if ((Duty[0] <= 54)&(Duty[0] > 50))
            {
            *((unsigned *) (modulator + 1)) =   2*(*PWM_PERIOD)*(4/100);    
            }
            else
            {
            *((unsigned *) (modulator + 1)) =   2*(*PWM_PERIOD)*(Duty[0]-50)/100;            
            } 
            *((unsigned *) (modulator + 2)) = 0x3; // enable CW
        }
        else
        {
            if (Duty[0] >= 46)
            {
            *((unsigned *) (modulator + 1)) =   2*(*PWM_PERIOD)*(4/100);    
            }
            else
            {
            *((unsigned *) (modulator + 1)) =   2*(*PWM_PERIOD)*(50-Duty[0])/100;         
            }
            *((unsigned *) (modulator + 2)) = 0x2; // Enable motor and enable CCW
        }
    }
    else
    {
        // Extra output port should be defined for the Direction
        *((unsigned *) (modulator + 1)) =   (*PWM_PERIOD)*(Duty[0])/100;   
        *((unsigned *) (modulator + 2)) = 0x2; // enable motor 
    }
}
else
{
    *((unsigned *) (modulator + 2)) = 0x0; // enable motor    
}
#endif

/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Terminate function
 *
 */
void zybo_pwm_Terminate_wrapper(real_T *xD,
			const uint32_T *PWM_BASE_ADDR, const int_T p_width0,
			const uint32_T *PWM_PERIOD, const int_T p_width1,
			const uint32_T *DUTY_LOWER_LIMIT, const int_T p_width2,
			const uint8_T *MOTOR_DIR_DECODING, const int_T p_width3)
{
/* %%%-SFUNWIZ_wrapper_Terminate_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Custom Terminate code goes here.
 */
#ifndef MATLAB_MEX_FILE
*((unsigned *) (modulator + 2)) = 0x0; // enable CCW	

munmap(modulator, MAP_SIZE);
#endif
/* %%%-SFUNWIZ_wrapper_Terminate_Changes_END --- EDIT HERE TO _BEGIN */
}


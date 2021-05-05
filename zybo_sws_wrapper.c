
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
int*  sws;
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
 * Start function
 *
 */
void zybo_sws_Start_wrapper(real_T *xD,
			const uint32_T *SWS_BASE_ADDR, const int_T p_width0)
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

sws = getVirtualAddress(*SWS_BASE_ADDR);

 
#endif
/* %%%-SFUNWIZ_wrapper_Start_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Output function
 *
 */
void zybo_sws_Outputs_wrapper(real_T *SWS,
			const real_T *xD,
			const uint32_T *SWS_BASE_ADDR, const int_T p_width0)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/* This sample sets the output equal to the input
      y0[0] = u0[0]; 
 For complex signals use: y0[0].re = u0[0].re; 
      y0[0].im = u0[0].im;
      y1[0].re = u1[0].re;
      y1[0].im = u1[0].im;
 */
#ifndef MATLAB_MEX_FILE

value = *((unsigned *) (sws + 0));
for(int i = 0; i< 4; i++)
    SWS[i]=0;
if (value & 0x1 )
{
    SWS[0]=1;
}
else
{
    SWS[0]=0;
}
if (value & 0x2 )
{
    SWS[1]=1;
}
else
{
    SWS[1]=0;
}
if (value & 0x4 )
{
    SWS[2]=1;
}
else
{
    SWS[2]=0;
}
if (value & 0x8 )
{
    SWS[3]=1;
}
else
{
    SWS[3]=0;
}
#endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Updates function
 *
 */
void zybo_sws_Update_wrapper(real_T *SWS,
			real_T *xD,
			const uint32_T *SWS_BASE_ADDR, const int_T p_width0)
{
/* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Code example
 *   xD[0] = u0[0];
 */
#ifndef MATLAB_MEX_FILE
value = *((unsigned *) (sws + 0));

#endif
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Terminate function
 *
 */
void zybo_sws_Terminate_wrapper(real_T *xD,
			const uint32_T *SWS_BASE_ADDR, const int_T p_width0)
{
/* %%%-SFUNWIZ_wrapper_Terminate_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Custom Terminate code goes here.
 */
#ifndef MATLAB_MEX_FILE

munmap(sws, MAP_SIZE);

#endif
/* %%%-SFUNWIZ_wrapper_Terminate_Changes_END --- EDIT HERE TO _BEGIN */
}


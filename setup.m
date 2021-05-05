

%add path to the custom board disign, should not be changed
%addpath(fullfile('..','board','HDLCoder_ZYBO_Z7_10_2'))
%enable the model property EnableLBRepository. Your library can appear
%in the browser only if this property is on when you save your library.
%set_param(gcs,'EnableLBRepository','on');
%add libraries to simulink library browser
%addpath('Cstm_Interfaces');

%sampling time and frequency
t_sample = 0.0005;  %desired sampling time
f_pga = 100 * 10^6;                     %fpga clock frequency, 100MHz
t_fpga = 1/f_pga;                       %fpga clock time period
oversampleFactor = t_sample / t_fpga;   %factor used in HDL coder, copy this number when using HDL workflow advisor


%Input filter
s=tf('s');
%InputFilter = 1/(0.1*s+1);
%InputFilter = 1/1;
InputFilter =tf(1,1);
%discrete filter
InputFilter_dis = c2d(InputFilter,t_sample,"tustin");
[InputFilter_dis_num,InputFilter_dis_den]=tfdata(InputFilter_dis,'v');

% controller
%ki = 3;
%C = ki/s;
%[Cnum,Cden]=tfdata(C,'v');
%C_dis = c2d(C,t_sample,"tustin");
%[Cdis_num,Cdis_den]=tfdata(C_dis,'v');

%Filter to remove noises from the scope in output when reading sensors
%OutputFilter = 1/(0.001*s+1);
%OutputFilter = 1/1;
OutputFilter = tf(1,1);
%discrete filter
OutputFilter_dis = c2d(OutputFilter,t_sample,"tustin");
[OutputFilter_dis_num2,OutputFilter_dis_den2]=tfdata(OutputFilter_dis,'v');

%open simulink model
open_system('ZyboPWMGenTest')
open_system('Receive_data')
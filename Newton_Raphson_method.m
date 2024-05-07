clc, clear, close all;
 
E=10^(-5); %Es
 
x0=1.8; 
y0=3.5; 
 
f1=x0^2+y0^2-16; %first circle 
f2=(x0-4)^2+(y0-4)^2-5; %second circle
 
d1_x=2*x0;%d(f1)/dx
d1_y=2*y0;%d(f1)/dy
d2_x=(2*x0)-8;%d(f2)/dx
d2_y=(2*y0)-8;%d(f2)/dy
 
format long %%for more digits
 
while 1
 
x1=x0-((f1*d2_y)-(f2*d1_y))/((d1_x*d2_y)-(d1_y*d2_x)); %x new root
y1=y0-((f2*d1_x)-(f1*d2_x))/((d1_x*d2_y)-(d1_y*d2_x)); %y new root
xe=(x1-x0)/x1; % x error
ye=(y1-y0)/y1; % y error
 
if ((abs(xe)<E)&&(abs(ye)<E))% comparing Es and other erorrs
 
 disp(x1)
 disp(y1)
 
 break;
 
else
x0=x1; %make new x root 
y0=y1; %make new y root 
 
f1=x0^2+y0^2-16; % first circle
f2=(x0-4)^2+(y0-4)^2-5; %second circle
d1_x=2*x0;
 
d1_y=2*y0;
d2_x=(2*x0)-8;
d2_y=(2*y0)-8;
 
end
 
end

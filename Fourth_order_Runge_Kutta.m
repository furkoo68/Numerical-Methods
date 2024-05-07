clc, clear, close all;
f_y=@(x,y,z) z; %the first derivative of the problem
f_z=@(x,y,z) -1.5*z - 1.5628*y + 0.5*sin(x); %the second derivative the
problem
x(1)=0;
y(1)=5;
z(1)=3;
h=0.5;
x_last_val=5;
n=ceil((x_last_val-x(1))/h);
for ii=1:n
x(ii+1)=x(ii)+h;
r1_y=f_y(x(ii),y(ii),z(ii));
r1_z=f_z(x(ii),y(ii),z(ii));
r2_y=f_y(x(ii)+h/2,y(ii)+h/2*r1_y,z(ii)+h/2*r1_z);
r2_z=f_z(x(ii)+h/2,y(ii)+h/2*r1_y,z(ii)+h/2*r1_z);
r3_y=f_y(x(ii)+h/2,y(ii)+h/2*r2_y,z(ii)+h/2*r2_z);
r3_z=f_z(x(ii)+h/2,y(ii)+h/2*r2_y,z(ii)+h/2*r2_z);
r4_y=f_y(x(ii)+h,y(ii)+h*r3_y,z(ii)+h*r3_z);
r4_z=f_z(x(ii)+h,y(ii)+h*r3_y,z(ii)+h*r3_z);
y(ii+1)=y(ii)+h/6*(r1_y+2*r2_y+2*r3_y+r4_y);
z(ii+1)=z(ii)+h/6*(r1_z+2*r2_z+2*r3_z+r4_z);
end
figure
plot(x,y,'color','#77AC30','Marker','o','linewidth',2');
title('Fourth-order Runge-Kutta method ');
xlabel('x');
ylabel('y(x)');
grid on

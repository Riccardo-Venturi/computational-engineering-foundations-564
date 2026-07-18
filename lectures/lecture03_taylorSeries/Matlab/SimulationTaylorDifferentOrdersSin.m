clear all, close all, clc %cleancommandc

t=-10:0.01:10;
y=sin(t);
plot(t,y,"k")
axis([-10 10 -10 10])

grid on, hold on


%%first order Taylor expansion

P=[1 0]; % x + 0;
yT1 = polyval(P,t);
plot(t,yT1, 'b--', 'LineWidth', 1.5)

%% III order Taylor expansion

P_III=[-1/factorial(3) 0 1 0] % -( 1/6 * x^3 ) + (0 * x^2) + (1 * x^1) + (0 * x^0)

yT3=polyval(P_III,t);
plot(t,yT3, 'r--')

%% Fifth-order Taylor expansion
P = [1/factorial(5) 0 -1/factorial(3) 0 1 0]; % -(1/3!)x^3 + x + 0;
yT5 = polyval(P,t);
plot(t,yT5,'g--','LineWidth',1.2)

%% Seventh-order Taylor expansion
P = [-1/factorial(7) 0 1/factorial(5) 0 -1/factorial(3) 0 1 0]; % -(1/3!)x^3 + x + 0;
yT7 = polyval(P,t);
plot(t,yT7,'m--','LineWidth',1.2)

%% Ninth-order Taylor expansion
P = [1/factorial(9) 0 -1/factorial(7) 0 1/factorial(5) 0 -1/factorial(3) 0 1 0]; % -(1/3!)x^3 + x + 0;
yT9 = polyval(P,t);
plot(t,yT9,'c--','LineWidth',1.2)

input("press enter to exit... ")

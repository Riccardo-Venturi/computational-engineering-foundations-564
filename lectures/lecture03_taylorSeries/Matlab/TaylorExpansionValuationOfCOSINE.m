%%Valutazione del cos con Matlab/octave
%%Pol = 1 -x^2/2 +x^4/4! ..... taylor series of cos

clear all; close all; clc

%continous cos study
x=[-10:0.1:10];

cos_x=cos(x);
plot(x, cos_x, 'b')
axis([-10 10 -10 10])

grid on, hold on

%%taylor order 8 %%

P=[1/factorial(8) 0 -1/factorial(6) 0 1/factorial(4) 0 -1/factorial(2) 0 1]

Ty_cos=polyval(P,x)

plot(x,Ty_cos, '--r')

input('press enter to move on...')

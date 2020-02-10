clc
clear all
main_window = figure('Name', 'Lab01', 'Units', 'Normalized', 'Position', [0, 0, 0.5, 0.8], 'Visible', 'off', 'MenuBar', 'none', 'Resize', 'on');
movegui(main_window, 'center');
set(main_window, 'Visible', 'on');
datacursormode on
ax1 = axes('Units', 'Normalized', 'Position', [0.05, 0.25, 0.9, 0.70]);
grid(ax1, 'on');
tb1 = axtoolbar(ax1,'default');
tb1.Visible = 'on';
%%%%%%%%Parameters
r = 10;
q = 10;
N = 20;
Nx = N;
Ny = N;
F = 5;
H = 1;
mu = 1;
beta = 1;

A = -(beta/(2*mu)) + ((beta/(2*mu))^2 + (pi/q)^2)^0.5;
B = -(beta/(2*mu)) - ((beta/(2*mu))^2 + (pi/q)^2)^0.5;
C1 = (1 - exp(B*r))/(exp(A*r) - exp(B*r));
C2 = 1 - C1;


[x,y] = meshgrid(0:0.2:r,0:0.2:q);


Psi = zeros(size(x,1), size(x,1));
U = zeros(Nx, Ny);
V =  zeros(Nx, Ny);

for i=1:size(x,1)
    for j=1:size(x,1)
        Psi(i,j) = (F/(mu*(pi/q)^2)) * (C1*exp(A*x(i,j)) + C2*exp(B*x(i,j)) - 1) * sin((pi*y(i,j))/q);
        U(i,j) = (F/(mu*(pi/q))) * (C1*exp(A*x(i,j)) + C2*exp(B*x(i,j)) - 1) * cos((pi*y(i,j))/q);
        V(i,j) = -(F/(mu*(pi/q)^2)) * (C1*A*exp(A*x(i,j)) + C2*B*exp(B*x(i,j))) * sin((pi*y(i,j))/q);
    end
end

%contour(x, y, Psi, 20);
quiver(x,y,U,V, 6);


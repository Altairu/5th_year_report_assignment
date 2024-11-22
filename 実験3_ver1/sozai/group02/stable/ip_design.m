clear
format compact

% a  = 8.74e+00;
% b  = 1.23e+00;
% 
% m  = 2.30e-01;
% l  = 3.05e-01;
% g  = 9.81e+00;
% Jg = 1.42e-02;
% c  = 1.79e-03;

% *********** 台車系のパラメータ ***********
a  = 8.33;
b  = 1.21;

% *********** 振子系のパラメータ ***********
m  = 2.30e-01;
l  = 3.05e-01;
Jg = 9.55e-03;
c  = 8.31e-04;
g  = 9.81e+00;

disp(' ')
disp(' ************** 固有値の指定 ************** ')
p(1) = input('p1 = ');
p(2) = input('p2 = ');
p(3) = input('p3 = ');
p(4) = input('p4 = ');

%%%%%%%%%%%%
J = Jg + m*l^2;

%%%%%%%%%%%%
E = [ 1  0  0  0
      0  1  0  0 
      0  0  1  0
      0 m*l 0  J ];

F = [ 0  1    0    0
      0 -a    0    0
      0  0    0    1
      0  0  m*l*g -c ];

G = [ 0
      b
      0
      0 ];

%%%%%%%%%%%%
A = inv(E)*F;
B = inv(E)*G;

K = - acker(A,B,p);

disp(' ')
disp(' ******** 状態フィードバックゲイン ******** ')
fprintf('k1 = %3.2e\n',K(1));
fprintf('k2 = %3.2e\n',K(2));
fprintf('k3 = %3.2e\n',K(3));
fprintf('k4 = %3.2e\n',K(4));

%%%%%%%%%%%%
eigen = eig(A + B*K);

disp(' ')
disp(' ************ A + B*K の固有値 ************ ')
eigen
%fprintf('%3.2e + %3.2e i\n',real(eigen(1)),imag(eigen(1)));
%fprintf('%3.2e + %3.2e i\n',real(eigen(2)),imag(eigen(2)));
%fprintf('%3.2e + %3.2e i\n',real(eigen(3)),imag(eigen(3)));
%fprintf('%3.2e + %3.2e i\n',real(eigen(4)),imag(eigen(4)));

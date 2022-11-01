% FOR HELICOPTER NR 3-10
% This file contains the initialization for the helicopter assignment in
% the course TTK4115. Run this file before you execute QuaRC_ -> Build 
% to build the file heli_q8.mdl.

% Oppdatert høsten 2006 av Jostein Bakkeheim
% Oppdatert høsten 2008 av Arnfinn Aas Eielsen
% Oppdatert høsten 2009 av Jonathan Ronen
% Updated fall 2010, Dominik Breu
% Updated fall 2013, Mark Haring
% Updated spring 2015, Mark Haring

%% INIT, ALLTID TJØH!
%%%%%%%%%%% Calibration of the encoder and the hardware for the specific
%%%%%%%%%%% helicopter
Joystick_gain_x = 1;
Joystick_gain_y = -1;
PORT = 4;


%%%%%%%%%%% Physical constants
g = 9.81; % gravitational constant [m/s^2]
l_c = 0.46; % distance elevation axis to counterweight [m]
l_h = 0.66; % distance elevation axis to helicopter head [m]
l_p = 0.175; % distance pitch axis to motor [m]
m_c = 1.92; % Counterweight mass [kg]
m_p = 0.72; % Motor mass [kg]

V_s0 = 7; % Found by testing
K_f = (2*l_h*m_p*g - m_c*g*l_c)/(l_h*V_s0);

%% LAB 1
%%%%%%%%%%% Poles
lambda_1 = -3;
lambda_2 = 0.2;

%%%%%%%%%%% Parameters found under preparatory lab work (lab 1)
L1 = l_p*K_f;
L2 = m_c*g*l_c - 2*m_p*g*l_h;
L3 = l_h*K_f;
L4 = L3;

J_p = 2*m_p*l_p^2;
J_e = m_c*l_c^2 + 2*m_p*l_h^2;
J_lambda = m_c*l_c^2 + 2*m_p*(l_h^2 + l_p^2);

K1 = L1/J_p;
K2 = L3/J_e;
K3 = -L2*L4/(L3*J_lambda);

K_pp = lambda_1*lambda_2/K1;
K_pd = (-lambda_1-lambda_2)/K1;


%% LAB 2.1

A = [0 1 0; 0 0 0; 0 0 0];
B = [0 0; 0 (l_p*K_f/J_p); (l_h*K_f/J_e) 0];
C = [1 0 0; 0 0 1];
D = 0;

Q_LQR = 0.000001*[1 0 0; 0 1 0; 0 0 1];
R_LQR = 0.000001*[1 0; 0 1];

K = lqr(A, B, Q_LQR, R_LQR);

F = [K(1,1) K(1,3); K(2,1) K(2,3)];

%% LAB 2.2

A = [0 1 0 0 0; 0 0 0 0 0; 0 0 0 0 0; -1 0 0 0 0; 0 0 -1 0 0];
B = [0 0; 0 (l_p*K_f/J_p); (l_h*K_f/J_e) 0; 0 0; 0 0];
C = [1 0 0; 0 0 1];
D = 0;
G = [0 0; 0 0; 0 0; 1 0; 0 1];

Q_LQR = [1 0 0 0 0; 0 1 0 0 0; 0 0 1 0 0; 0 0 0 1 0; 0 0 0 0 1]
R_LQR = [1 0; 0 1]

K = lqr(A, B, Q_LQR, R_LQR)

F = [K(1,1) K(1,3); K(2,1) K(2,3)]

%% LAB 3

dev_states_IMU = [0.02 -0.039];
dev_rates_IMU = [0; 0.044; 0.043];

A = [0 1 0 0 0; 0 0 0 0 0; 0 0 0 0 0; -1 0 0 0 0; 0 0 -1 0 0];
B = [0 0; 0 (l_p*K_f/J_p); (l_h*K_f/J_e) 0; 0 0; 0 0];
C = [1 0 0; 0 0 1];
D = 0;
G = [0 0; 0 0; 0 0; 1 0; 0 1];

A_L = [0 1 0 0 0; 0 0 0 0 0; 0 0 0 1 0; 0 0 0 0 0; -L2/J_lambda 0 0 0 0];
B_L = [0 0; 0 (l_p*K_f/J_p); 0 0; (l_h*K_f/J_e) 0; 0 0];
C_L = eye(5);
D_L = 0;

Q_LQR = [1 0 0 0 0; 0 1 0 0 0; 0 0 2 0 0; 0 0 0 1 0; 0 0 0 0 1];
R_LQR = [1 0; 0 1];

[K,S,CLP] = lqr(A, B, Q_LQR, R_LQR)

CLP

F = [K(1,1) K(1,3); K(2,1) K(2,3)]

r_p = 10;
p1 = -r_p*cos(5*pi/72) - r_p*sin(5*pi/72)*1i;
p2 = -r_p*cos(5*pi/72) + r_p*sin(5*pi/72)*1i;
p3 = -r_p*cos(5*pi/144) - r_p*sin(5*pi/144)*1i;
p4 = -r_p*cos(5*pi/144) + r_p*sin(5*pi/144)*1i;
p5 = -10;

p = [p1 p2 p3 p4 p5]
L = place(A_L', C_L', p)'

%% LAB 4

dev_states_IMU = [0.02 -0.039];
dev_rates_IMU = [0; 0.044; 0.043];

%Setting Timestamp to 2ms
Ts = 0.002;

A_c = [0 1 0 0 0 0;
       0 0 0 0 0 0;
       0 0 0 1 0 0;
       0 0 0 0 0 0;
       0 0 0 0 0 1;
       (-L2/J_lambda) 0 0 0 0 0;];

B_c = [0 0;
       0 (l_p*K_f)/J_p;
       0 0;
       (l_h*K_f)/J_e 0;
       0 0;
       0 0;];
%Change observability matrix from lambda_dot to lambda
C_c = [0 0 1 0 0 0;
       0 0 0 0 1 0;];
D_c = 0;

Ob = [C_c;
      C_c*A_c;
      C_c*A_c^2;
      C_c*A_c^3;
      C_c*A_c^4;
      C_c*A_c^5;];
  
SYSC = ss(A_c,B_c,C_c,D_c);

% Continious to Discrete

[SYSD, G] = c2d(SYSC, Ts, 'tustin');


% Kalman

x0 = [0; 0; -pi/6; 0; 0; 0;];
R_d = 0;
Q_d = eye(6);
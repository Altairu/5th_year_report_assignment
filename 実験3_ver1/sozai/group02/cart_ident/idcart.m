clear
format compact
close all

load cart_data     % kP = 100; zc = 0.1;
% load cart_data2      % kP = 1500; zc = 0.1;
% load cart_data3      % kP = 100; zc = 0.2;



%%%%%
[zmax,i] = max(z);
Amax  = zmax - zc;
Tpeak = t(i);

fprintf('\n\n');
fprintf('**********************************\n');
fprintf('オーバシュート Amax  = %3.2e\n',Amax);
fprintf('最大ピーク時間 Tpeak = %3.2e\n',Tpeak);
fprintf('**********************************\n');

%%%%%
xi     = - (1/Tpeak)*log(Amax/zc);
omegan = sqrt((pi/Tpeak)^2 + xi^2);
zeta   = xi/omegan;

fprintf('**********************************\n');
fprintf('ωn1 = %3.2e\n',omegan);
fprintf('ζ1  = %3.2e\n',zeta);
fprintf('**********************************\n');

%%%%%
a = 2*zeta*omegan;
b = omegan^2/kP;

fprintf('**********************************\n');
fprintf('a = %3.2e\n',a);
fprintf('b = %3.2e\n',b);
fprintf('**********************************\n');
fprintf('\n\n');

%%%%%
zsim = zc*step(omegan^2,[1 2*zeta*omegan omegan^2],t);

figure(1)
set(gcf,'Position',[100 100 560 420]) % [x0 y0 width height]
subplot('position',[0.2 0.2 0.7 0.7]) % [left bottom width height]
plot(t,z,'r','linewidth',2);
hold on
plot(t,zsim,'b--','linewidth',2);

plot(Tpeak,zmax,'o','linewidth',2,'markersize',8,'color',[0 0.6902 0.3137]);
plot([0 Tpeak],[zmax zmax],'k--','linewidth',0.25);
plot([Tpeak Tpeak],[0 zmax],'k--','linewidth',0.25);

set(gca,'fontsize',16,'fontname','arial')

text(0.4*Tpeak,0.1*zmax,'$${T}_{\rm peak}$$','interpreter','latex','fontsize',20)
text(0.05,0.95*zmax,'$${z}_{\rm max}$$','interpreter','latex','fontsize',20)

legend('Experiment data','Simulation data',4);

xlabel('time [s]','fontsize',18,'fontname','arial');
ylabel('position [m]','fontsize',18,'fontname','arial');

xlim([0 1])
%ylim([0 0.06])
set(gca,'xtick',[0:0.25:1])
%set(gca,'ytick',2*[0:0.01:0.03])

plot([0 1],zc*[1 1],'k--','linewidth',0.25);
hold off

% ---------------------------------
figure(2)
set(gcf,'Position',[200 200 560 420]) % [x0 y0 width height]
subplot('position',[0.2 0.2 0.7 0.7]) % [left bottom width height]
plot(t,v,'r','linewidth',2);

set(gca,'fontsize',16,'fontname','arial')
legend('Experiment data',1);

xlabel('time [s]','fontsize',18,'fontname','arial');
ylabel('voltage [V]','fontsize',18,'fontname','arial');

xlim([0 1])
set(gca,'xtick',[0:0.25:1])
ylim([-10 10])
set(gca,'ytick',[-10:5:10])

% ---------------------------------
figure(1)
set(gcf,'PaperPositionMode','auto')
print -dpdf    figure_idcart.pdf
print -dbitmap figure_idcart.bmp

figure(2)
set(gcf,'PaperPositionMode','auto')
print -dpdf    figure_idcart_u.pdf
print -dbitmap figure_idcart_u.bmp


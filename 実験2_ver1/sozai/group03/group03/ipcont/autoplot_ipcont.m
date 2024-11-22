clear
format compact

close all

figure(1); subplot(1.1,1.1,1.05)
figure(2); subplot(1.1,1.1,1.05)
figure(3); subplot(1.1,1.1,1.05)

% ----------------------------------------------
load ipcont_data1
wn = 15;
zeta = 0.3;
y_m = step(wn^2,[1 2*zeta*wn wn^2],t);

figure(1); plot(t,y,'r','linewidth',2); hold on
figure(2); plot(t,u,'r','linewidth',2); hold on
figure(3); plot(t,y_m,'r','linewidth',2); hold on

% ----------------------------------------------
load ipcont_data2
wn = 15;
zeta = 0.7;
y_m = step(wn^2,[1 2*zeta*wn wn^2],t);

figure(1); plot(t,y,'g--','linewidth',2); hold on
figure(2); plot(t,u,'g--','linewidth',2); hold on
figure(3); plot(t,y_m,'g--','linewidth',2); hold on

% ----------------------------------------------
load ipcont_data3
wn = 15;
zeta = 1;
y_m = step(wn^2,[1 2*zeta*wn wn^2],t);

figure(1); plot(t,y,'b-.','linewidth',2); hold on
figure(2); plot(t,u,'b-.','linewidth',2); hold off
figure(3); plot(t,y_m,'b-.','linewidth',2); hold on

% ----------------------------------------------
figure(1); plot([0 1],[1 1],'k','linewidth',0.5); hold off
figure(3); plot([0 1],[1 1],'k','linewidth',0.5); hold off

% ----------------------------------------------
figure(1)
set(gca,'fontsize',18,'fontname','arial')
% xlabel('time [s]','fontsize',20,'fontname','arial')
% ylabel('angle [rad]','fontsize',20,'fontname','arial')
xlabel('$t$ [s]','interpreter','latex','fontsize',22)
ylabel('$\theta(t)$ [rad]','interpreter','latex','fontsize',22)
xlim([0 1])
ylim([0 1.5])
set(gca,'xtick',0:0.2:1)
set(gca,'ytick',0:0.5:1.5)

legend({'${\omega}_{\rm M}=15,\ {\zeta}_{\rm M}=0.3\sb{\sb{\sb{}}}$',...
        '${\omega}_{\rm M}=15,\ {\zeta}_{\rm M}=0.7\sb{\sb{\sb{}}}$',...
        '${\omega}_{\rm M}=15,\ {\zeta}_{\rm M}=1$'},4,'interpreter','latex','fontsize',22)

figure(2)
set(gca,'fontsize',18,'fontname','arial')
% xlabel('time [s]','fontsize',20,'fontname','arial')
% ylabel('voltage [V]','fontsize',20,'fontname','arial')
xlabel('$t$ [s]','interpreter','latex','fontsize',22)
ylabel('$v(t)$ [V]','interpreter','latex','fontsize',22)
xlim([0 1])
ylim([-5 10])
set(gca,'xtick',0:0.2:1)
set(gca,'ytick',-5:5:10)

figure(3)
set(gca,'fontsize',18,'fontname','arial')
% xlabel('time [s]','fontsize',20,'fontname','arial')
% ylabel('angle [rad]','fontsize',20,'fontname','arial')
xlabel('$t$ [s]','interpreter','latex','fontsize',22)
ylabel('${y}_{\rm M}(t)$ [rad]','interpreter','latex','fontsize',22)
% title('responses of reference model','fontsize',20,'fontname','arial')
xlim([0 1])
ylim([0 1.5])
set(gca,'xtick',0:0.2:1)
set(gca,'ytick',0:0.5:1.5)

% ----------------------------------------------
figure(1); print -dpdf figure_ipcont_angle.pdf
figure(2); print -dpdf figure_ipcont_volt.pdf
figure(3); print -dpdf figure_ipcont_model.pdf

figure(1); print -dbitmap figure_ipcont_angle.bmp
figure(2); print -dbitmap figure_ipcont_volt.bmp
figure(3); print -dbitmap figure_ipcont_model.bmp

clear
format compact

close all

figure(1); subplot(1.1,1.1,1.05)
figure(2); subplot(1.1,1.1,1.05)

load pcont_kP02_data
figure(1); plot(t,y,'r-.','linewidth',2); hold on
figure(2); plot(t,u,'r-.','linewidth',2); hold on

load pcont_kP04_data
figure(1); plot(t,y,'g--','linewidth',2); hold on
figure(2); plot(t,u,'g--','linewidth',2); hold on

load pcont_kP20_data
figure(1); plot(t,y,'b','linewidth',2); hold on
figure(2); plot(t,u,'b','linewidth',2); hold off


figure(1)
plot([0 1],[0.4 0.4],'k','linewidth',0.5); hold off
set(gca,'fontsize',18,'fontname','arial')
xlabel('time [s]','fontsize',20,'fontname','arial')
ylabel('angle [rad]','fontsize',20,'fontname','arial')
xlim([0 1])
ylim([0 0.6])
set(gca,'xtick',0:0.2:1)
set(gca,'ytick',0:0.2:0.6)
legend({'${k}_{\rm P}=2\sb{\sb{\sb{}}}$','${k}_{\rm P}=4\sb{\sb{\sb{}}}$','${k}_{\rm P}=20$'},4,'interpreter','latex','fontsize',22)

figure(2)
set(gca,'fontsize',18,'fontname','arial')
xlabel('time [s]','fontsize',20,'fontname','arial')
ylabel('voltage [V]','fontsize',20,'fontname','arial')
xlim([0 1])
ylim([-5 10])
set(gca,'xtick',0:0.2:1)
set(gca,'ytick',-5:5:10)

figure(1); print -dpdf figure_pcont_angle.pdf
figure(2); print -dpdf figure_pcont_volt.pdf

figure(1); print -dbitmap figure_pcont_angle.bmp
figure(2); print -dbitmap figure_pcont_volt.bmp



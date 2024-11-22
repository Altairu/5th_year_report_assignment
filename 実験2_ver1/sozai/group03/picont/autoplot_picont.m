clear
format compact

close all

figure(1); subplot(1.1,1.1,1.05)
figure(2); subplot(1.1,1.1,1.05)

load picont_kP04_kI00_data
figure(1); plot(t,y,'r-.','linewidth',2); hold on
figure(2); plot(t,u,'r-.','linewidth',2); hold on

load picont_kP04_kI06_data
figure(1); plot(t,y,'g--','linewidth',2); hold on
figure(2); plot(t,u,'g--','linewidth',2); hold on

load picont_kP04_kI12_data
figure(1); plot(t,y,'b','linewidth',2); hold on
figure(2); plot(t,u,'b','linewidth',2); hold on


figure(1)
plot([0 4],[0.4 0.4],'k','linewidth',0.5); hold off
set(gca,'fontsize',18,'fontname','arial')
xlabel('time [s]','fontsize',20,'fontname','arial')
ylabel('angle [rad]','fontsize',20,'fontname','arial')
xlim([0 4])
ylim([0 0.6])
set(gca,'xtick',0:1:4)
set(gca,'ytick',0:0.2:0.6)
legend({'${k}_{\rm P}=4,\ {k}_{\rm I}=0\sb{\sb{\sb{}}}$',...
        '${k}_{\rm P}=4,\ {k}_{\rm I}=6\sb{\sb{\sb{}}}$',...
        '${k}_{\rm P}=4,\ {k}_{\rm I}=12$'},4,'interpreter','latex','fontsize',22)

figure(2)
plot([0 4],[0 0],'k','linewidth',0.5); hold off
set(gca,'fontsize',18,'fontname','arial')
xlabel('time [s]','fontsize',20,'fontname','arial')
ylabel('voltage [V]','fontsize',20,'fontname','arial')
xlim([0 4])
ylim([-0.5 2])
set(gca,'xtick',0:1:4)
set(gca,'ytick',-0.5:0.5:2)

figure(1); print -dpdf figure_picont_angle.pdf
figure(2); print -dpdf figure_picont_volt.pdf

figure(1); print -dbitmap figure_picont_angle.bmp
figure(2); print -dbitmap figure_picont_volt.bmp



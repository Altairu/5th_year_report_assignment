clear
format compact

load ad_da_data

close all
figure(1)
subplot(1.1,1.1,1.05)
plot(t,y,'b','linewidth',2)
hold on
plot([0 8],[180 180],'k')
plot([0 8],[-180 -180],'k')
hold off

set(gca,'fontsize',18,'fontname','arial')
xlabel('time [s]','fontsize',20,'fontname','arial')
ylabel('angle [deg]','fontsize',20,'fontname','arial')

xlim([0 8])
ylim([-200 200])
set(gca,'xtick',0:1:8)
set(gca,'ytick',-180:90:180)

figure(1); print -dpdf figure_ad_da.pdf
figure(1); print -dbitmap figure_ad_da.bmp

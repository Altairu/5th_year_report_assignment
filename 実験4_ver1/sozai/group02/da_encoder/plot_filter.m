clear
format compact

load filter_data

% -----------------------------------
figure(1)
set(gcf,'Position',[100 100 560 420]) % [x0 y0 width height]
subplot('position',[0.2 0.2 0.7 0.7]) % [left bottom width height]
plot(t,z,'r','linewidth',2);

set(gca,'fontsize',16,'fontname','arial')
ylim([0 0.2])

xlabel('time [s]','fontsize',18,'fontname','arial');
ylabel('position [m]','fontsize',18,'fontname','arial');

set(gcf,'PaperPositionMode','auto')
print -dpdf    figure_filter_z.pdf
print -dbitmap figure_filter_z.bmp

% -----------------------------------
figure(2)
set(gcf,'Position',[100 100 560 420]) % [x0 y0 width height]
subplot('position',[0.2 0.2 0.7 0.7]) % [left bottom width height]
plot(t,dz,'r','linewidth',2);

set(gca,'fontsize',16,'fontname','arial')
ylim([0 0.2])

xlabel('time [s]','fontsize',18,'fontname','arial');
ylabel('velocity [m/s]','fontsize',18,'fontname','arial');

set(gcf,'PaperPositionMode','auto')
print -dpdf    figure_filter_dz.pdf
print -dbitmap figure_filter_dz.bmp

% -----------------------------------
figure(3)
set(gcf,'Position',[100 100 560 420]) % [x0 y0 width height]
subplot('position',[0.2 0.2 0.7 0.7]) % [left bottom width height]
plot(t,dzf1,'r','linewidth',2);

set(gca,'fontsize',16,'fontname','arial')
ylim([0 0.2])

xlabel('time [s]','fontsize',18,'fontname','arial');
ylabel('velocity [m/s] (with LPF)','fontsize',18,'fontname','arial');

set(gcf,'PaperPositionMode','auto')
print -dpdf    figure_filter_dzf1.pdf
print -dbitmap figure_filter_dzf1.bmp

% -----------------------------------
figure(4)
set(gcf,'Position',[100 100 560 420]) % [x0 y0 width height]
subplot('position',[0.2 0.2 0.7 0.7]) % [left bottom width height]
plot(t,dzf2,'r','linewidth',2);

set(gca,'fontsize',16,'fontname','arial')
ylim([0 0.2])

xlabel('time [s]','fontsize',18,'fontname','arial');
ylabel('velocity [m/s] (with LPF)','fontsize',18,'fontname','arial');

set(gcf,'PaperPositionMode','auto')
print -dpdf    figure_filter_dzf2.pdf
print -dbitmap figure_filter_dzf2.bmp

% -----------------------------------
figure(5)
set(gcf,'Position',[100 100 560 420]) % [x0 y0 width height]
subplot('position',[0.2 0.2 0.7 0.7]) % [left bottom width height]
plot(t,dzf3,'r','linewidth',2);

set(gca,'fontsize',16,'fontname','arial')
ylim([0 0.2])

xlabel('time [s]','fontsize',18,'fontname','arial');
ylabel('velocity [m/s] (with LPF)','fontsize',18,'fontname','arial');

set(gcf,'PaperPositionMode','auto')
print -dpdf    figure_filter_dzf3.pdf
print -dbitmap figure_filter_dzf3.bmp


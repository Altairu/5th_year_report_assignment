clear
format compact

close all

% ----------------------------
load ident_data

length_data = length(dy);
K = mean(dyf(round(0.5*length_data):end));

for i=1:length_data
  if dyf(i) < 0.632*K & dyf(i+1) > 0.632*K
     k = i;
  end
end
T = t(k);

a = 1/T;
b = a*K;

% ----------------------------
fprintf('\n\n ************************ ')
fprintf('\n K = %3.2e',K)
fprintf('\n T = %3.2e',T)
fprintf('\n ************************ ')
fprintf('\n a = %3.2e',a)
fprintf('\n b = %3.2e',b)
fprintf('\n ************************ \n\n ')

% ----------------------------
figure(1); subplot(1.1,1.1,1.05)
stairs(t,dy,'m','linewidth',0.5); hold on
stairs(t,dyf,'b','linewidth',1); hold off

set(gca,'fontsize',18,'fontname','arial')
xlabel('time [s]','fontsize',20,'fontname','arial')
ylabel('velocity [rad/s]','fontsize',20,'fontname','arial')
xlim([0 0.5])
ylim([-1.5 3])
set(gca,'xtick',0:0.1:0.5)
set(gca,'ytick',-1.5:1.5:3)

legend({' exact differential$\sb{\sb{}}\sp{\sp{\sp{\sp{}}}}$',' inexact differential$\sb{\sb{}}$'},4,'interpreter','latex','fontsize',22)

% ----------------------------
dy_sim = K*(1 - exp(-t/T));

figure(2); subplot(1.1,1.1,1.05)
stairs(t,dyf,'b','linewidth',1); hold on
plot(t,dy_sim,'m--','linewidth',2); hold on

plot([0 t(end)],[K K],'k')
plot([0 t(end)],[0 0],'k')
plot([0 t(end)],0.632*[K K],'k')
plot([T T],[0 0.632*K],'k'); hold off

set(gca,'fontsize',18,'fontname','arial')
xlabel('time [s]','fontsize',20,'fontname','arial')
ylabel('velocity [rad/s]','fontsize',20,'fontname','arial')
xlim([0 0.5])
ylim([0 2])
set(gca,'xtick',0:0.1:0.5)
set(gca,'ytick',0:0.5:2)

text(0.7*T,-0.12,'$T$','interpreter','latex','fontsize',20);
text(0.505,K,'$K$','interpreter','latex','fontsize',20);
text(0.505,0.632*K,'63.2\%','interpreter','latex','fontsize',20);

legend({' inexact differential$\sb{\sb{}}\sp{\sp{\sp{\sp{}}}}$',' identification result$\sb{\sb{}}$'},4,'interpreter','latex','fontsize',22)

% ----------------------------
figure(1); print -dpdf figure_lowpass.pdf
figure(2); print -dpdf figure_ident.pdf

figure(1); print -dbitmap figure_lowpass.bmp
figure(2); print -dbitmap figure_ident.bmp


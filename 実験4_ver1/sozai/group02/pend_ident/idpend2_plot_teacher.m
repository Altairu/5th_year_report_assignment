clear
format compact

idpend2_teacher
close all
save data2 omega_n zeta
clear
load data2

load pend_data2

t_data     = t;
phi_data = phi;
clear t phi


%%%%% 0`10•bŠÔ‚Ìƒf[ƒ^‚ðíœ %%%%%

count=1;
for i=1:1:size(t_data,1)
 if t_data(i) >= 10 
    t(count,1)     = t_data(i) - 10;
    phi(count,1) = phi_data(i);
    count= count + 1; 
 end     
end

close all
figure(1)
set(gcf,'Position',[100 100 560*2 420]) % [x0 y0 width height]
subplot('position',[0.2 0.2 0.7 0.7]) % [left bottom width height]
plot(t,phi,'linewidth',1)
hold on

%%%%% peak_time & peak_value %%%%%
a = 0;

count = 1;
x = -1;
for i=2:1:length(t)
    if phi(i-1) > 0 & phi(i-1) < phi(i)
            a = t(i,1);
            x = -1;
    end
    if phi(i-1) > 0 & phi(i-1) > phi(i) & phi(i-1) > x 
            x = phi(i-1,1);
            b = t(i-1,1); 
            c = (a + b)/2;
            peak_value(count,1) = phi(i-1,1);
            peak_time(count,1)  = c;
            count = count + 1;
    end
end


if peak_value(1) < peak_value(2)
	s = size(peak_value,1);
	peak_value2 = peak_value;
	peak_time2  = peak_time;
	peak_value  = 0;
	peak_time   = 0;
	peak_value(1:s-1,1) = peak_value2(2:s);
	peak_time(1:s-1,1)  = peak_time2(2:s);
end

% figure(1); subplot(2,1,1)
% plot(peak_time,peak_value,'ro','linewidth',1)
% hold off



%%%%% Œ¸Š—¦, ŒÅ—LŠpU“®” %%%%%
% disp(' ******************************************** ')
% disp(' ************* ƒÖn2CƒÄ2 ‚Ì“ü—Í ************* ')
% disp(' ******************************************** ')
% omega_n = input('ƒÖn2 = ');
% zeta    = input('ƒÄ2  = ');

omega_d = omega_n*sqrt(1 - zeta^2);

t_sim = 0:0.01:20;
y0 = peak_value(1);
phi = atan(sqrt(1 - zeta^2)/zeta);
y_sim = y0/sqrt(1-zeta^2)*exp(-zeta*omega_n*t_sim).*sin(omega_d*t_sim + phi);

figure(1)
plot(t_sim+peak_time(1),y_sim,'r--','linewidth',2)
hold off


% -------------------------------
figure(1)
set(gca,'fontsize',16)
set(gca,'fontname','arial')

xlabel('time [s]','fontsize',18,'fontname','arial');
ylabel('angle [rad]','fontsize',18,'fontname','arial');

axis([0 20 -0.9 0.9])
set(gca,'xtick',0:5:20)
set(gca,'ytick',-0.9:0.3:0.9)

grid

legend('experiment result','simulation result',4)

set(gcf,'PaperPositionMode','auto','PaperType','a3')
print -dpdf    figure_idpend2_plot.pdf
print -dbitmap figure_idpend2_plot.bmp


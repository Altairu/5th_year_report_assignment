clear
format compact
close all

load pend_data

t_data   = t;
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

figure(1)
set(gcf,'Position',[100 100 560*2 420]) % [x0 y0 width height]
subplot('position',[0.2 0.2 0.7 0.7]) % [left bottom width height]
plot(t,phi,'linewidth',2)
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

figure(1)
plot(peak_time,peak_value,'o','linewidth',2,'markersize',8,'color',[0 0.6902 0.3137])
hold off


%%%%% ŽüŠú %%%%%
count = 1;
for i = 1:1:length(peak_time)-1
    T(count,1) = peak_time(i+1) - peak_time(i);
    count = count+1;
end
total = 0;
Tave = 0;
for i=1:10
    total=total + T(i);
end
Tave=total/10;

figure(2)
set(gcf,'Position',[150 150 560 420]) % [x0 y0 width height]
subplot('position',[0.2 0.2 0.7 0.7]) % [left bottom width height]

plot([1:10],T(1:10),'o','linewidth',2,'markersize',8,'color',[0 0.6902 0.3137])
hold on
plot([1 10],Tave*[1 1],'linewidth',1)
hold off


%%%%% Œ¸Š—¦ %%%%%

count = 1;
for i = 1:1:length(peak_value)-1
    lambda(count,1) = peak_value(i+1)/peak_value(i);
    count = count + 1;
end
total = 0;
lambda_ave = 0;
for i = 1:10
    total = total + lambda(i);
end
lambda_ave = total/10;

figure(3)
set(gcf,'Position',[200 200 560 420]) % [x0 y0 width height]
subplot('position',[0.2 0.2 0.7 0.7]) % [left bottom width height]

plot([1:10],lambda(1:10),'o','linewidth',2,'markersize',8,'color',[0 0.6902 0.3137])
hold on
plot([1 10],lambda_ave*[1 1],'linewidth',1)
hold off




% -------------------------------
figure(1)
set(gca,'fontsize',16)
set(gca,'fontname','arial')

xlabel('time [s]','fontsize',18,'fontname','arial');
ylabel('angle [rad]','fontsize',18,'fontname','arial');

axis([0 20 -1.5 1.5])
set(gca,'xtick',0:5:20)
set(gca,'ytick',-1.5:0.5:1.5)

grid

% -------------------------------
figure(2)
set(gca,'fontsize',16)
set(gca,'fontname','arial')

xlabel('$$i$$','interpreter','latex','fontsize',20);
ylabel('$${T}_{i}$$ [s]','interpreter','latex','fontsize',20);

axis([1 10 1 1.8])
set(gca,'xtick',1:10)
set(gca,'ytick',1:0.2:1.8)

grid

% -------------------------------
figure(3)
set(gca,'fontsize',16)
set(gca,'fontname','arial')

xlabel('$$i$$','interpreter','latex','fontsize',20);
ylabel('$${\lambda}_{i}$$','interpreter','latex','fontsize',20);

axis([1 10 0.8 1.1])
set(gca,'xtick',1:10)
set(gca,'ytick',0.8:0.1:1.1)

grid

% -------------------------------------------------
disp('========================')
disp('ŽüŠú')
disp('========================')
for i=1:10
  fprintf('T%d = %5.4e\n',i,T(i))
end
sum_T = 0;
for i=1:10
    sum_T = sum_T + T(i);
end
fprintf('•½‹Ï = %5.4e\n',sum_T/10)

fprintf('\n')

disp('========================')
disp('Œ¸Š—¦')
disp('========================')
for i=1:10
  fprintf('lambda%d = %5.4e\n',i,lambda(i))
end
sum_lambda = 0;
for i=1:10
    sum_lambda = sum_lambda + lambda(i);
end
fprintf('•½‹Ï = %5.4e\n',sum_lambda/10)



%%%%% Œ¸Š—¦, ŒÅ—LŠpU“®” %%%%%

omega_d = (2*pi)/Tave;
omega_n =((omega_d)/(2*pi))*sqrt(((2*pi).^2)+(log(lambda_ave)).^2);
zeta = sqrt(1-((omega_d).^2)/((omega_n).^2));

%%%%% UŽq‚Ìƒpƒ‰ƒ[ƒ^ %%%%%

m = 0.230;
l = 0.305;
g = 9.81;

J  = (m*l*g)/(omega_n.^2);

Jg = J - m*l^2;
c  = 2*J*zeta*omega_n;

fprintf('ƒÖn2 = %5.4e\n',omega_n)
fprintf('ƒÄ2  = %5.4e\n',zeta)

fprintf('m  = %3.2e\n',m)
fprintf('l  = %3.2e\n',l)
fprintf('g  = %3.2e\n',g)
fprintf('Jg = %3.2e\n',Jg)
fprintf('c  = %3.2e\n',c)

figure(1)
set(gcf,'PaperPositionMode','auto','PaperType','a3')
print -dpdf    figure_idpend.pdf
print -dbitmap figure_idpend.bmp

figure(2)
set(gcf,'PaperPositionMode','auto')
print -dpdf    figure_idpend_T.pdf
print -dbitmap figure_idpend_T.bmp

figure(3)
set(gcf,'PaperPositionMode','auto')
print -dpdf    figure_idpend_lambda.pdf
print -dbitmap figure_idpend_lambda.bmp


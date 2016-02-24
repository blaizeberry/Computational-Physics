Plummer = dlmread('Plummer.txt');
Plummer = Plummer';
r = zeros(1,10000);
rad = zeros(1,10000);
rho = zeros(1,10000);
rhoth = zeros(1,10000);
M = zeros(1,10000);
Mth = zeros(1,10000);
v = zeros(1,10000);
vth = zeros(1,10000);

for i = 1:10000
    r(1,i) = (Plummer(1,((i-1)*6 + 1))^2 + Plummer(1,((i-1)*6 + 2))^2 + Plummer(1,((i-1)*6 + 3))^2)^(0.5);
end

for i = 1:10000
    v(1,i) = (Plummer(1,((i-1)*6 + 4))^2 + Plummer(1,((i-1)*6 + 5))^2 + Plummer(1,((i-1)*6 + 6))^2)^(0.5);
end

for i = 1:10000
   counter = 0;
   for j = 1:10000
       if r(1,j) < 0.02 + i/100
           counter = counter + 1;
       end
   end
   rad(1,i) = log(0.02 + i/100);
   
%    rho(1,i) = (counter/10000)*3/(4*3.14159*(0.02 + i/1000)^3);
   
   M(1,i) = counter;
   Mth(1,i) = 10000*((0.02 + i/100)^3)/(1+(0.02 + i/100)^2)^(1.5);

   if i > 1
     rho(1,i) = (M(1,i) - M(1,(i-1)))/(40000*3.14159*((0.02 + (i-1)/100)^2)*(1/100));
   elseif i == 1
     rho(1,1) = counter/10000;
   end
   rhoth(1,i) = 3*(1 + (0.02 + i/100)^2)^(-2.5)/(4*3.14159);
   
end

figure
plot(rad(1,:), Mth(1,:), rad(1,:), M(1,:))
xlabel('log (r)')
ylabel('M (r)')
legend('M (r) theoretical','M (r) numerical','Location','northwest')

figure
plot(rad(1,:), rho(1,:))

figure
plot(rad(1,:), rhoth(1,:), rad(1,:), rho(1,:))
xlabel('log (r)')
ylabel('\rho (r)')
legend('\rho (r) theoretical','\rho (r) numerical')
axis([-3 3 -0.05 0.5])

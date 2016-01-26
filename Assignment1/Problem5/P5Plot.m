Halley = [];

Halley(:,1:3) = csvread('HaleyComet.csv');

plot3(Halley(:,1),Halley(:,2),Halley(:,3))
title('Halley Comet Orbit')
xlabel('x (AU)')
ylabel('y (AU)')
zlabel('z (AU)')
print('HalleyComet','-dpng')

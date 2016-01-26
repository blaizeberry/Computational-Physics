plot(D(:,1),D(:,2),D(:,3),D(:,4),D(:,5),D(:,6))
title('Problem 1B')
xlabel('x')
ylabel('v')
legend('x_0 = 1','x_0 = 2','x_0 = 3')


plot3(D(:,1),D(:,2),C(:,1),D(:,3),D(:,4),C(:,1),D(:,5),D(:,6),C(:,1))
title('Problem 1B 3D')
xlabel('x')
ylabel('v')
zlabel('t')
legend('x_0 = 1','x_0 = 2','x_0 = 3')
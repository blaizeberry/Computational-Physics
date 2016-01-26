plot(E(:,1),E(:,2),E(:,3),E(:,4),E(:,5),E(:,6))
title('Problem 1C')
xlabel('x')
ylabel('v')
legend('x_0 = 1','x_0 = 2','x_0 = 3')


plot3(E(:,1),E(:,2),C(:,1),E(:,3),E(:,4),C(:,1),E(:,5),E(:,6),C(:,1))
title('Problem 1C 3D')
xlabel('x')
ylabel('v')
zlabel('t')
legend('x_0 = 1','x_0 = 2','x_0 = 3')
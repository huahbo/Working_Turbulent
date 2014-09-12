function  mean_u = mean_computation(U) 
for j=1:64
sumx=0;
sumy=0.;
sumz=0.;
for k=1:64
for i=1:64
sumx=sumx+U(i,j,k);
end
end
mean_u(j)=sumx/(64^2);
end

function output=array_reader(input, ldx, ldy, ldz)
  output = zeros(ldz,ldy,ldx);
for k=1:ldz
        for j=1:ldy
                for i=1:ldx
                        output(i,j,k)=input((k-1)*ldy*ldx+(j-1)*ldx+i);
end
end
end

fopen('convection0.bin')
convection=array_reader_z(fread(ans,'double'),64,64,64);

fopen('viscous0.bin')
viscous=array_reader_z(fread(ans,'double'),64,64,64);

fopen('pressure0.bin')
pressure=array_reader_z(fread(ans,'double'),64,64,64);


fopen('explicit0.bin')
explicit=array_reader_z(fread(ans,'double'),64,64,64);

fopen('u_tilda0.bin')
u_tilda=array_reader_z(fread(ans,'double'),66,64,64);

fopen('v_tilda0.bin')
v_tilda=array_reader_z(fread(ans,'double'),64,66,64);

fopen('w_tilda0.bin')
w_tilda=array_reader_z(fread(ans,'double'),64,64,66);

fopen('rhs0.bin')
rhs0=fread(ans,'double');
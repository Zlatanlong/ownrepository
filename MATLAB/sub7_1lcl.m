clc,clear,close all
txdata=imread('lena.bmp'); % ͼ�� ���� ����
% imshow(txdata);
double_data=double(txdata); % ͼ��� ת�� double �� �� ����
SNRdB=11;
[size_m,size_n]=size(double_data);
max_dec=max(double_data(:));
codelen=ceil(log2(max_dec));
databin=fun_dec2bin(double_data,codelen);%ʮ����ת��Ϊ������
data_demapping=fun_BPSK_awgn(databin,SNRdB);%ӳ���������ӳ��
datadec=fun_bin2dec(data_demapping,codelen);%������ת��Ϊʮ����
dataout=reshape(datadec,[size_m,size_n]);%��ʮ��������ת��Ϊ��ǰ�ĸ�ʽ
y=uint8 (dataout); %�����ն˰��д����Ϊ Ϊ dataout
imshow(y) % ͼ�� ��ʾ
biterr(double_data,dataout)
function bin=fun_dec2bin(dec,len)
bin=dec2bin(dec,len)-48;
end
function dec=fun_bin2dec(bin,len)
% gs=length(bin)/len;
% bin=reshape(bin,[],gs);
bin=reshape(bin,[],len);
% bin=bin';
dec=bin2dec(num2str(bin))';
end
function out=fun_BPSK_awgn(in,dB)
%ӳ��
% in=in';
in=in(:);
for k=1:length(in)
    if(in(k)==0) 
        code(k)=1;
    else
        code(k)=-1;
    end
end
%������
awgn_info=awgn(code,dB,'measured');
%��ӳ��
for k=1:length(awgn_info)
    if(awgn_info(k)>=0) 
        out(k)=0;
    else
        out(k)=1;
    end
end
% biterr(in,out)
end

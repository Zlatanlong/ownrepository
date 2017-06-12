clc,clear,close all
txdata=imread('lena.bmp'); % 图像 读入 命令
% imshow(txdata);
double_data=double(txdata); % 图像成 转成 double 型 型 数据
SNRdB=11;
[size_m,size_n]=size(double_data);
max_dec=max(double_data(:));
codelen=ceil(log2(max_dec));
databin=fun_dec2bin(double_data,codelen);%十进制转换为二进制
data_demapping=fun_BPSK_awgn(databin,SNRdB);%映射加噪声反映射
datadec=fun_bin2dec(data_demapping,codelen);%二进制转换为十进制
dataout=reshape(datadec,[size_m,size_n]);%将十进制数列转换为以前的格式
y=uint8 (dataout); %若接收端按行处理后为 为 dataout
imshow(y) % 图像 显示
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
%映射
% in=in';
in=in(:);
for k=1:length(in)
    if(in(k)==0) 
        code(k)=1;
    else
        code(k)=-1;
    end
end
%加噪声
awgn_info=awgn(code,dB,'measured');
%反映射
for k=1:length(awgn_info)
    if(awgn_info(k)>=0) 
        out(k)=0;
    else
        out(k)=1;
    end
end
% biterr(in,out)
end

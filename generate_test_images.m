clc;clear;
src=repmat(255,[512,512]);
result=[];
dx=repmat(255,[512,512]);
dy=repmat(255,[512,512]);

for r=1:512
    for c=1:512
        dx(r,c)=round(2e-06*(r-256)^3-8e-2*(r-256));
        dy(r,c)=round(2e-06*(c-256)^3-8e-2*(c-256));
    end
end

i=0;
for c=30-8:50:500
    for r=30-8:50:500
        i=i+1;
        marks{i}=generate_rand_box();
        src(r:r+15,c:c+15)=marks{i};
    end
end

figure,imshow(src,[]);

dst=repmat(255,[512,512]);
i=0;
for c=30:50:500
    for r=30:50:500
        i=i+1;
        shiftr=dy(r,c);
        shiftc=dx(r,c);
        dst(r+shiftr-8:r+shiftr+15-8,c+shiftc-8:c+shiftc+15-8)=marks{i};
        result=[result;
                c,r,shiftc,shiftr];
    end
end
figure,imshow(dst,[]);

src=uint8(src);
dst=uint8(dst);
imwrite(src,'src.tif');
imwrite(dst,'dst.tif');

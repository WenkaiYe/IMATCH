function dst=generate_rand_box(box_height,box_width,p,val)
if(nargin<4)
    val=0;
    if(nargin<3)
        p=0.6;
        if(nargin==0)
            box_height=16;
            box_width=16;
        end
    end
end

assert(p<=1 && p>=0,'ERROR');
num_all=box_height*box_width;
num_pts=round(num_all*p);

dst=repmat(255,box_height,box_width);

for i=1:num_pts
    r=(1+floor(rand()*(box_width-0.1)));
    c=(1+floor(rand()*(box_height-0.1)));
    dst(r,c)=val;
end

% dst(1,:)=repmat(val,1,box_width);
% dst(end,:)=repmat(val,1,box_width);
% dst(:,1)=repmat(val,box_height,1);
% dst(:,end)=repmat(val,box_height,1);
end

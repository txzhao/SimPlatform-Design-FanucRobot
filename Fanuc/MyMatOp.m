function ret=MyMatOp(A,B)
Jnt=size(A,2);
for i=1:Jnt
    for j=i:Jnt
        ret(i,10*(j-1)+1:10*j) = MyVecOp(A(6*(i-1)+1:6*i,j),B(6*(j-1)+1:6*j,1));
    end
end
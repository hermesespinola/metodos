function [ X ] = ge( A, b )
% ge: Gaussian Elimination
%
% A method for solving matrix equations of the form Ax = b.

[n m] = size(A);

if n ~= m
  error('A must be a square matrix');

elseif n ~= size(b)(1)
  error('A and b sizes do not match');
end

X = zeros(size(A)(1), 1);

% Matrix triangulation
for i=1:n
  temp = A(i:end,i:end);
  m = temp(2:end, 1) ./ temp(1);
  temp(2:end, :) = (temp(2:end, :) - m * temp(1, :));
  A(i:end,i:end) = temp;
end

X(end) = b(end) ./ A(end);

% Backward substitution
for i=n-1:-1:1
  X(i) = (b(i) - sum(-(A(i+1:end,i) .* X(i+1:end)))) ./ A(i, i);
end

end % ge

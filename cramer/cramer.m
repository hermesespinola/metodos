function [ X ] = cramer( A, b )

[n m] = size(A);

if n ~= m
  error('A must be a square matrix');
elseif n ~= size(b)(1)
  error('A and b sizes do not match');
end

X = zeros(n, 1);
S = zeros(n, 1);
delta = det(A);

for i=1:n
  temp = A;
  temp(:, i) = b;
  S(i) = det(temp);
end

X = S ./ delta;

end % cramer

function [ X ] = gj( A, b )

C = [A b]; % Matriz aumentada
m = length(C(:,1))

for i=1:m
  if C(i,i) ~= 1
      C(i,:) = C(i,:) ./ C(i,i);  % divide toda la fila por C(i,i)
  end

  for n=1:m
    if n ~= i
        C(n,:) = -C(n,i) .* C(i,:) + C(n,:); % Entonces se convierte a 0
    end
  end
end

X = C(:, end);
end  % gj

%Laboratorul 3
%Exercitiul 1-i)
% se extrag pe rand aleator 3 bile, simulare eveniment de
% 5000 si returneaza proportia de simulari in care cel putin
% o bila extrasa este rosie

function simulare1()
  urna=['R','R','R','R','R','A','A','A','V','V'];
  count=0;

  for i = 1:5000
    v = randsample(urna,3);
    val = find(v=='R');
    if length(val) ~= 0
      count = count + 1;
    endif
  endfor

  out = count/5000
end

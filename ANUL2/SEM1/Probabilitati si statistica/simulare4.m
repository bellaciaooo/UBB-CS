%Laboratorul 3
%Exercitiul 1-iv)
% se extrag pe rand aleator 3 bile, simulare eveniment de
% 5000 si returneaza proportia de simulari in care toate
% bilele au aceasi culoare, relativ la cel putin o bila
% este rosie => A^B/A

function simulare4()
  urna=['R','R','R','R','R','A','A','A','V','V'];
  countA=0;
  countAB=0;

  for i = 1:5000
    v = randsample(urna,3);
    val = find(v=='R');
    if length(val) ~= 0
      countA = countA + 1;
    endif
    if length(val) == 3
      countAB = countAB + 1;
    endif
  endfor

  out = countAB/countA
end

%Laboratorul 4 ex 2
% 2. Un punct material se deplaseaza pe axa reala dintr-un nod spre un nod
% vecin, la fiecare pas, cu probabilitatea p ∈ (0, 1) la dreapta ¸si cu
% probabilitea 1 − p la stanga. Nodurile sunt centrate in numerele intregi,
% iar nodul initial este 0:
% a) Simulati o astfel de deplasare cu k ∈ N* pasi, cu probabilitatea p∈(0, 1)
% si returnati pozitiile curente la fiecare pas.
% b) Simulati de m ∈ N* ori o astfel de deplasare cu k ∈ N* pasi, cu
% probabilitatea p ∈ (0, 1),si afisati histograma pozitiilor finale. Care
% este pozitia finala cel mai des intalnita (sau pozitiile finale
% cel mai des intalnite)?
% ---putin dubioasa

function p1 = lab4ex2(k)
     p=0.5;
     poz_curenta=0;
     poz = zeros(1,k+1);
     for i=1:k
        fprintf('%d  ',poz_curenta);
        step = 2*binornd(1,p)-1;
        poz_curenta+=step;
        poz(i)=poz_curenta;
    endfor

    clf;grid on; hold on;
    p=0.5;
    n=20;
    x=binornd(n,p,1,k);
    N=hist(x,0:n);
    bar(0:n,N/k,'hist','FaceColor','green');
    bar(0:n,binopdf(0:n,n,p),'FaceColor','blue');
    legend('probabilitatile estimate','probabilitatile teroretice');
    set(findobj('type','patch'),'facealpha',0.7);
    xlim([-1 n+1]);

endfunction

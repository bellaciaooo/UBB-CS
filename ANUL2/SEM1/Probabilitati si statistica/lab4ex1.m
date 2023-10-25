%Laboratorul 4 ex 1
% 1. Salvati fisierele keywords_spam.txt si keywords_ham.txt, care contin
% liste de cuvinte cheie extrase din email-uri spam, respectiv ham.
% Implementati in Octave o clasificare naiva Bayes care stabileste daca un
% email este spam sau ham, calculand probabilitatile corespunzatoare date de
% frecventele relative de aparitii, respectiv neaparitii, ale cuvintelor cheie
% in listele date (neglijati cuvintele din email care nu apar in liste).
% Testati programul cu urmatoarele email-uri:
%1) “invite your friend today to click here”
%2) “call your friend today it’s urgent thank you”.

function out =lab4ex1 ( )
    %citim din fisiere
    fileID = fopen('keywords_ham.txt','r');
    ham=textscan(fileID,'%s');
    fclose(fileID);

    fileID = fopen('keywords_spam.txt','r');
    spam=textscan(fileID,'%s');
    fclose(fileID);

    fileID = fopen('email.txt','r');
    email = textscan(fileID,'%s');
    fclose(fileID);

    %cuvintele din cele doua fisiere
    words=unique([ham{1};spam{1}]);
    fprintf(' %s',words{:}); fprintf('.\n');

    fprintf('Numarul de cuvinte spam: %d.\n',numel(spam{1}));
    fprintf('Numarul de cuvinte ham: %d.\n',numel(ham{1}));
    nr_spam = numel(spam{1});
    nr_ham = numel(ham{1});

    nr_cuvinte = nr_spam + nr_ham;
    fprintf('Numarul de cuvinte total: %d.\n',nr_cuvinte);

    fprintf('Probabilitate ham: %d.\n',nr_ham/nr_cuvinte);
    fprintf('Probabilitate spam: %d.\n',nr_spam/nr_cuvinte);

    p_spam = nr_spam/nr_cuvinte;
    p_ham = nr_ham/nr_cuvinte;

    %aplicam Bayes
    for i=1:numel(words)
        if ismember(words{i},email{1})
          p_spam *= sum(strcmp(words{i},spam{1}))/nr_spam;
          p_ham *= sum(strcmp(words{i},ham{1}))/nr_ham;
  else
         p_spam *= 1-sum(strcmp(words{i},spam{1}))/nr_spam;
         p_ham *= 1-sum(strcmp(words{i},ham{1}))/nr_ham;
  endif
endfor

fprintf('Probabilitate spam 2: %d.\n',p_spam);
fprintf('Probabilitate ham 2:%d.\n',p_ham);
endfunction

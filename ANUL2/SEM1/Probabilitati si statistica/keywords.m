function out=keywords()
  fileID = fopen('keywords_ham.txt','r');
  ham=textscan(fileID,'%s');
  fclose(fileID);

  fileID = fopen('keywords_spam.txt','r');
  spam=textscan(fileID,'%s');
  fclose(fileID);

  fileID = fopen('email.txt','r');
  email=textscan(fileID,'%s');
  fclose(fileID);

  %cuvintele unice din cele doua fisiere
  words=unique([ham{1};spam{1}])

  %nr de cuvinte spam si ham
  nr_spam = numel(spam{1})
  nr_ham = numel(ham{1})
  nr_cuvinte = nr_spam + nr_ham;
  fprintf('\n');

  %probabilitatile emailului sa fie spam sau ham
  fprintf('Numarul de cuvinte total: %d.\n',nr_cuvinte);
  fprintf('Probabilitate ham: %d.\n',nr_ham/nr_cuvinte);
  fprintf('Probabilitate spam: %d.\n',nr_spam/nr_cuvinte);

  p_spam = nr_spam/nr_cuvinte;
  p_ham = nr_ham/nr_cuvinte;

  %aplicam Bayes
  for i=1:numel(words)
    if ismember(words{i},email{1})
      p_spam = p_spam * (sum(strcmp(words{i},spam{1}))/nr_spam);
      p_ham = p_ham * (sum(strcmp(words{i},ham{1}))/nr_ham);
    else
      p_spam = p_spam * (1-sum(strcmp(words{i},spam{1}))/nr_spam);
      p_ham = p_ham * (1-sum(strcmp(words{i},ham{1}))/nr_ham);
    endif
  endfor
  if(p_ham>p_spam)
    printf('Emailul se trimite in inbox.\n');
  else
    printf('Emailul se trimite in spam.\n');
  endif
endfunction

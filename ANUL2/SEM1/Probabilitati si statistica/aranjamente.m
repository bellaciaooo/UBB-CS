%functie pentru aranjamente de n luate cate k
function out=aranjamente(v=[],k)

  mat = nchoosek(v,k);
  %out = mat;

  nr = rows(mat);
  col = columns(mat);
  for i = 1:nr
     vector = [];
     for j = 1:col
       vector = [vector mat(i,j)];
     endfor
     disp(perms(vector))
  endfor

  end

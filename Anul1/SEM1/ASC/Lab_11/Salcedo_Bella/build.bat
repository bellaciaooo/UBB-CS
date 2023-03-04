nasm -fobj main_lab11_ex9.asm
nasm -fobj modul_lab11_ex9.asm

alink main_lab11_ex9.obj modul_lab11_ex9.obj -oPE -subsys console -entry start
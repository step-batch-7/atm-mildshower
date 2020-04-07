 #! /bin/zsh

rm -rf *.o

if [[ ! -d bin ]]; then
  mkdir bin;
fi

gcc -c *.c
gcc -o ${1/#/bin\/} *.o
rm -rf *.o
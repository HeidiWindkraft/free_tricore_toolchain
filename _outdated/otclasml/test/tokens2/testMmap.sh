#! /bin/bash

make clean
make
./main.elf Tokens_CallTableCall.lasm > TestOutCurMmap.txt
diff -us TestOutExp.txt TestOutCurMmap.txt


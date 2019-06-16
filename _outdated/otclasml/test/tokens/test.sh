#! /bin/bash

make clean
make
./main.elf < Tokens_CallTableCall.lasm > TestOutCur.txt
diff -us TestOutExp.txt TestOutCur.txt



include ../../make/boost_env.mak

main.elf: main.cxx
	g++ -I../../src -I$(BOOST_INCLUDE_BASE) -I../include $^ -o $@ -Wall -std=c++11 -O3 \
		../../src/otclasml/cmaps.cxx \
		../../src/otclasml/ConstStringMap.cxx

.PHONY: clean

clean:
	rm main.elf


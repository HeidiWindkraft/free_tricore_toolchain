
include ../../make/boost_env.mak

main.elf: main.cxx
	g++ -I$(BOOST_INCLUDE_BASE) $^ -o $@ -Wall -std=c++11 -O3 $(BOOST_IOSTREAMS_LIB)

.PHONY: clean

clean:
	rm main.elf


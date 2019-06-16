
include ../../make/boost_env.mak

# -std=gnu++11 -std=c++11 ?

main.elf: main.cxx
	g++ -I../../src -I$(BOOST_INCLUDE_BASE) $^ -o $@ -Wall -std=c++11 -O3 $(BOOST_IOSTREAMS_LIB)

.PHONY: clean

clean:
	rm main.elf


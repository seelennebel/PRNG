rng: xor.cpp utils.cpp main.cpp lfsr.cpp
	clang++ -o rng \
	main.cpp \
	utils.cpp \
	lfsr.cpp \
	xor.cpp
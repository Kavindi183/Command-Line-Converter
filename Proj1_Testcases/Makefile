# CO222 - 2016 Project 1

#List of test input files
TESTS	:=	$(wildcard *.inp)

.SUFFIXES : .inp .out

test : $(TESTS:.inp=.out)

%.out : %.inp %.exp
	@`cat $<` > $@ || printf ""
	@sdiff -Wib $(<:.inp=.exp) $@ || printf "ERROR: input $< failed \n"

.PHONY clean :
	-rm -f *.out *.o *.d core
-include $(SRCS:.c=.d)

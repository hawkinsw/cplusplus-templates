#assert_template.cpp         template_calculation.cpp
#assert_template_simple.cpp  template.cpp
all:$(patsubst %.cpp,%,$(wildcard *.cpp))

%: %.cpp
	g++ -std=c++11 -o $@ $?
	g++ -std=c++11 -o $@.s -S $? 

clean:
	rm -f $(patsubst %.cpp,%,$(wildcard *.cpp)) $(patsubst %.cpp,%.s,$(wildcard *.cpp)) a.out 

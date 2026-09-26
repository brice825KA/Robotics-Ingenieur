src =   $(wildcard main.cpp src/*.cpp)

obj =   $(src:.cpp=.o)

cc  =   clang++

bin =   parser

flags   =   -std=c++20 -g3

all: $(bin)

$(bin):   $(obj)
	    $(cc) $(src) $(flags) -o $(bin)
		rm -f *.o src/*.o

clean:
	    rm -f $(obj)

fclean:	clean
	rm -f $(bin)

re: fclean all
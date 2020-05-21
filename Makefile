GTKMM = `pkg-config gtkmm-3.0 --cflags --libs`
CC = g++
CFLAGS = $(GTKMM)
LDFLAGS = $(GTKMM)
SRC = Vue.cpp main.cpp Modele.cpp Area.cpp 
PROG = main
OBJS = $(SRC:.cpp=.o)
.SUFFIXES: .cpp .o

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

Area.o:Area.hpp PileL.hpp
Vue.o:Vue.hpp Observer.hpp Controleur.hpp PileL.hpp Robot.hpp Menu.hpp #TextView.hpp
Modele.o: Modele.hpp Observable.hpp PileL.hpp Exceptions.hpp
main.o: Vue.hpp Modele.hpp Controleur.hpp Vue2.hpp

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	rm -f *.o*~ core a.out $(PROG)


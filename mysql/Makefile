OBJ_C="demo_c"
OBJ_CC="demo_cc"
LIB="-lmysqlclient"

.PHNOY: demo_c demo_cc

all: clean demo_c demo_cc
demo_c:
	gcc demo.c test.c -o ${OBJ_C} ${LIB}
demo_cc:
	g++ demo.cc test.cc -o ${OBJ_CC}

clean:
	rm ${OBJ_C}
	rm ${OBJ_CC}

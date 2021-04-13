OBJ="demo_redis"
LIB="-lhiredis"

.PHONY: ${OBJ}

all: clean demo 

demo:
	g++ demo.cc test.cc -o ${OBJ} ${LIB}

clean:
	rm ${OBJ}

obj=datastructure.o 

test: $(obj)
	g++ -o test $(obj)

datastructure.o: sqlist.h


clean:
	rm $(obj)

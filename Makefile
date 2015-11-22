dotproduct:
	gcc dotproduct.c -o $@ -O0

.PHONY: clean

clean: 
	rm -f *.o *~ dotproduct
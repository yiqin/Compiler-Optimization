dotproduct:
	gcc dotproduct.c -o $@ -O0

dotproduct_timer:
	gcc dotproduct_timer.c -o $@ -O0

.PHONY: dotproduct dotproduct_timer clean

clean: 
	rm -f *.o *~ dotproduct dotproduct_timer
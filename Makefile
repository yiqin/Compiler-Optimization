dotproduct:
	gcc dotproduct.c -o $@ -O0

dotproduct_timer:
	gcc dotproduct_timer.c -o $@ -O0

dotproduct_timer_better:
	gcc dotproduct_timer_better.c -o $@ -O0

dotproduct_timer_optimized:
	gcc dotproduct_timer.c -o $@ -O3

.PHONY: dotproduct dotproduct_timer dotproduct_timer_better dotproduct_timer_optimized clean

clean: 
	rm -f *.o *~ dotproduct dotproduct_timer
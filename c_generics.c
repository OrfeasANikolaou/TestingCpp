#include <stdio.h>

#define point(scalar_type)	\
  struct {                	\
    scalar_type x;        	\
    scalar_type y;        	\
  }

int main(void)
{
  point(int) p    = {1, 2};
  point(double) q = {3.0, 4.0};

  printf("Int point. x: %d, y: %d\n", p.x, p.y);
  printf("Double point. x: %f, y: %f\n", q.x, q.y);
}

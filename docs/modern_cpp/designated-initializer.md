# Designated Initializer
Designated initializer is to resolve the correspondence between a list initializer and data members. Example below:
```c
#include <stdio.h>
typedef struct { int k; int l; int a[2]; } T;
typedef struct { int i;  T t; } S;
T x = {.l = 43, .k = 42, .a[1] = 19, .a[0] = 18 };
 // x initialized to {42, 43, {18, 19} }
int main(void)
{
    S l = { 1,          // initializes l.i to 1
           .t = x,      // initializes l.t to {42, 43, {18, 19} }
           .t.l = 41,   // changes l.t to {42, 41, {18, 19} }
           .t.a[1] = 17 // changes l.t to {42, 41, {18, 17} }
          };
    printf("l.t.k is %d\n", l.t.k); // .t = x sets l.t.k to 42 explicitly
                                    // .t.l = 41 would zero out l.t.k implicitly
}
```
In this way, the initializing list will initiallize each data member according to their `designator` (e.g. "`.t`" is one for member `t`), instead of according to the presence order. Note that `designator` can be nested (e.g. "`.t.l = 41`" from above).
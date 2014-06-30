bind
====

Bind in C

Ressources needed
-----------------

GCC compiler version 4.8 at least

You can install it with the following command:
* Fedora : `yum install gcc`
* Debian and Ubuntu : `apt-get install gcc`
* Archinux : `pacman -S gcc`

Usage exemple
-------------

```c
#include <stdio.h>

#include "bind.h"

int add(int a, int b)
{
    return a + b;
}

int main()
{
    int (*incr)(int) = bind1(int, add, int, 1);

    printf("incr(3) = %d\n", incr(3));
    return 0;
}
```

#### Code explanation

We first includes headers files **stdio.h** (for printf) and **bind.h** (for bind1, bind2, ...)

After that we declare a very simple **add** function that takes two *int* in parameter and returns the sum of them

In the main function we declare a function pointer which return an *int* and takes only 1 parameter

We affects it the return of **bind1** function

This function takes in this order:
- *int* : The return type of the bound function (Which is in our case the **add** function)
- *add* : The function to bind
- *int* : The type of the parameter that remain
- *1* : The binded parameter

After that you can call the new function like any other function pointer

#### Different bind function

If you open the bind.h file you will see 3 bind functions:
- **bind1** : 1 parameter remain
- **bind2** : 2 parameters remains
- **bind3** : 3 parameters remains

#### Todo

- Write a macro to choose which bind to use easier
- Fix a SegV when use it with [stdlist](https://github.com/Vins54/stdlist)
- Test with clang anonymous function

#### See also

A friend of mine as also write a bind function in C and ASM

You can see the result on his github:
https://github.com/BartholomewPanda/bind

/*

Find out (add code to print out) the address of the variable x in foo1, and the
variable y in foo2. What do you notice? Can you explain this?

*/

#include <stdio.h>
void foo1(int xval)
{
    int x;
    x = xval;
    printf("%p\n", &x);
}
void foo2(int dummy)
{
    int y;
    printf("%p\n", &y);

}
int main()
{
    foo1(7);
    foo2(11);
    return 0;
}
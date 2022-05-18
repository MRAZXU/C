# 1 "define2.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "define2.c"
# 9 "define2.c"
int main()
{
    int a = 1;
    int b = 2;
    int c[4] = {0};

    int s1 = (a) + (b);

    int s2 = (a) + (b) * (a) + (b);
    int m = ((a++) < (b) ? (a++) : (b));
    int d = sizeof(c)/sizeof(*c);






    return 0;
}

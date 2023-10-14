#include <stdio.h>
#include <time.h>
#include <stdint.h>

void foo(int a, int b, int c, int d)
{
  if (a && b && c)
    puts("first print");
  else if (b || c)
    puts("second print");
  
  puts("third print");

  if (c || d)
      puts("fourth print");

  sleep(1);
  puts("leaving foo...");
}

int main(int argc, char** argv) {
  foo((int)argv[0], (int)argv[1], (int)argv[2], (int)argv[3]); 
}

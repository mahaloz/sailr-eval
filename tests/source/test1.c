#include <stdio.h>
#include <time.h>
#include <stdint.h>

void foo(int a, int b, int c)
{
  if (a && b) {
    puts("first print");
  }

  puts("second print");
  
  if (b || c)
    puts("third print");

  sleep(1);
  puts("leaving foo...");
}

int main(int argc, char** argv) {
  foo((int)argv[0], (int)argv[1], (int)argv[2]); 
}

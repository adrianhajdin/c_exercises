#include <stdio.h>

typedef struct { 
  float r;
  float i; 
} complex;

complex add (complex a, complex b) {
  complex c;
  
  c.r = a.r + b.r;
  c.i = a.i + b.i;

  return c;
}

complex subtract (complex a, complex b) {
  complex c;
  
  c.r = a.r - b.r;
  c.i = a.i - b.i;

  return c;
}

complex multiply (complex a, complex b) {
  complex c;
  
  c.r = a.r * b.r - a.i * b.i;
  c.i = a.i * b.r + a.r * b.i;

  return c;
}

complex divide (complex a, complex b) {
  complex c;
  
  c.r = (a.r * b.r + a.i * b.i) / (b.r * b.r + b.i * b.i);
  c.i = (a.i * b.r - a.r * b.i) / (b.r * b.r + b.i * b.i);

  return c;
}

int main() {
  complex a, b, c; 
  char ch;

  scanf("%f %f\n", &a.r, &a.i);
  scanf("%f %f\n", &b.r, &b.i);
  scanf("%c", &ch);

  switch (ch){
    case '+':
      c = add(a, b);
      break;
    case '-':
      c = subtract(a, b);
      break;
    case '/':
      c = divide(a, b);
      break;
    case '*':
      c = multiply(a, b);
      break;
  }

  printf("%.2f %.2f", c.r, c.i);

  return 0;
}
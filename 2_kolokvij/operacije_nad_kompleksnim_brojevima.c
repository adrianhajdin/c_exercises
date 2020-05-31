#include <stdio.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

typedef struct {
  float re;
  float im;
} complex;

void calc(complex z1, complex z2, complex *suma, complex *razlika, complex *umnozak, complex *kolicnik);

int main() {
  complex z1, z2, suma, razlika, umnozak, kolicnik;

  scanf("%f %f", &z1.re, &z1.im);
  scanf("%f %f", &z2.re, &z2.im);

  calc(z1, z2, &suma, &razlika, &umnozak, &kolicnik);

  printf("%.2f\t%.2f\n", suma.re, suma.im);
  printf("%.2f\t%.2f\n", razlika.re, razlika.im);
  printf("%.2f\t%.2f\n", umnozak.re, umnozak.im);
  printf("%.2f\t%.2f\n", kolicnik.re, kolicnik.im);

  return 0;
}


void calc(complex z1, complex z2, complex *suma, complex *razlika, complex *umnozak, complex *kolicnik) {
  complex result;

  result.re = z1.re + z2.re;
  result.im = z1.im + z2.im;

  *suma = result;

  result.re = z1.re - z2.re;
  result.im = z1.im - z2.im;

  *razlika = result;

  result.re = z1.re * z2.re - z1.im * z2.im;
  result.im = z1.im * z2.re + z1.re * z2.im;

  *umnozak = result;

  float tmp1 = z1.re * z2.re + z1.im * z2.im;
  float tmp2 = z1.im * z2.re - z1.re * z2.im;
  float tmp3 = z2.re * z2.re + z2.im * z2.im;

  result.re = tmp1 / tmp3;
  result.im = tmp2 / tmp3;

  *kolicnik = result;
}
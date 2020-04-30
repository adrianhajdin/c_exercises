int main() {
    int number = 0;
    int *pnumber = NULL;

    pnumber = &number;

    printf("Address of the pointer: %p\n", &pnumbser);
    printf("Value of the pointer: %p\n", pnumber);
    printf("Value pointing to: %d\n", *pnumber);

    return 0;
}

// inicijalizirati pointere na null
// %p za printanje adrese pointera
// dereference koristeci indirection operator, *
// pointeri zauzimaju 8 bitova

// Operacije s pointerima:
// Assign an address to a pointer (array or variable with & or second pointer)
// Dereference a pointer (the * operatorsgives the value stored in the pointed-to location)
// Take a pointer address (the & operator tells you where the pointer itself is stored)
// Pointer arithmetic with + or - (useful with arrays)
// Find difference between two pointers (find out how far apart the elements in an array are)

// pointer to a constant
int value = 0;
const int *pvalue = &value;
// constant pointer
int value = 43;
int *const pvalue = &value;
// constant 
int value = 43;
const int *const pvalue = &value;

// Deklaracija pokazivaca
int *p = NULL;

// Inicijalizacija pokazivaca
p = &x;
p = malloc(100);

// Dereferenciranje pokazivaca
*p;

// Velicina pokazivaca

void uvecaj_drugi(int a[]) {
  a[1]++;
}

int main() {
    
int x[3] = {1, 2, 3};
    int *px;
    px = x;
    px = &x[0];  // isto kao i izraz u retku iznad
    x++;  // nije dozvoljeno
    px++; // dozvoljeno
  return 0;
}

char * p;             // p je pokazivač na char
char * const p;       // p je nepromjenjivi pokazivač na char
const char * p;       // p je pokazivač na nepromjenjivi char
const char * const p; // p je nepromjenjivi pokazivač na nepromjenjivi char
// deklaracije se čitaju s desna na lijevo Right-Left rule
// iznimka: const kada je skroz lijevo se odnosi na ono što je s njegove desne strane:
char const * p; // p je pokazivač na nepromjenjivi char
const char * p; // p je pokazivač na char (koji je nepromjenjiv)
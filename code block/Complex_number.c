#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct{
    float imag;
    float real;
}_COMPLEX;

void allocateComplexArray(_COMPLEX *c, int n){
    c = (_COMPLEX*)malloc(n * sizeof(_COMPLEX));
}

float Compute_magnitude(_COMPLEX c){
    float k;
    k = sqrt((c.real * c.real) + (c.imag * c.imag));
    return k;
}

float Compute_phase(_COMPLEX c){
    float k = atan(c.imag/c.real);
    return k;
}

_COMPLEX AddComplexNumber(_COMPLEX c1, _COMPLEX c2){
    _COMPLEX c;
    c.real = c1.real + c2.real;
    c.imag = c1.imag + c2.imag;
    return c;
}

_COMPLEX MultiplyComplexNumber(_COMPLEX c1, _COMPLEX c2){
    _COMPLEX c;
    c.real = c1.real * c2.real - c1.imag * c2.imag;
    c.imag = c1.imag * c2.real + c1.real * c2.imag;
    return c;
}

void printComplexNumber(_COMPLEX c){
    printf("%.3f + j%.3f\n", c.real, c.imag);
}

float* readSequence(int n){
    printf("Enter Sequence: ");
    float *arr = (float*)malloc(n * sizeof(float));
    for(int i = 0; i < n; i++)
        scanf("%f", &arr[i]);
    return arr;
}

void printRealSequence(float *arr, int n){
    printf("Real Sequence: ");
    for(int i = 0; i< n; i++)
        printf("%.3f ", arr[i]);
    printf("\n");
}

void printComplexSequence(_COMPLEX *c, int n){
    printf("Complex Sequences: \n");
    for(int i = 0; i< n; i++)
        printComplexNumber(c[i]);
}

void printMagnitudeSequence(_COMPLEX *c, int n){
    printf("Magnitude of Complex Numbers:\n");
    for(int i = 0; i< n; i++)
        printf("%.3f\n", Compute_magnitude(c[i]));

}

void printPhaseSequence(_COMPLEX *c, int n){
    printf("Phases of Complex Numbers:\n");
    for(int i = 0; i < n; i++)
        printf("%.3f\n", Compute_phase(c[i]));
}

_COMPLEX *ComputeDFT(float *arr, int n){
    _COMPLEX *c = (_COMPLEX*)malloc(n * sizeof(_COMPLEX));
    printf("Fourier transformation of Sequence:\n");

    for(int k = 0; k < n; k++){
        c[k].real = 0, c[k].imag = 0;
        for(int j = 0; j < n; j++){
            c[k].real = (c[k].real + arr[j] * cos(2 * 3.1415 * k * j / n));
            c[k].imag = (c[k].imag + arr[j] * sin(2 * 3.1415 * k * j / n));
        }
    }
    printComplexSequence(c, n);
    printMagnitudeSequence(c, n);
    printPhaseSequence(c, n);
    return c;
}

void ComputeIDFT(_COMPLEX *c, int n){
    printf("Inverse Fourier transformation of Sequence:\n");
    float *a = (float*)malloc(n * sizeof(float));

    for(int i = 0; i < n; i++){
        a[i] = 0;
        for(int j = 0; j < n; j++){
            a[i] += c[j].real * cos(2 * 3.1415 * i * j / n) + c[j].imag * sin(2 * 3.1415 * i * j / n);
        }
        a[i] /= n;
        printf("%.3f ", a[i]);
    }
    printf("\n");
}

int main(){
    _COMPLEX *c;
    int n;
    printf("Enter length of Sequence: ");
    scanf("%d", &n);
    float *arr = readSequence(n);
    allocateComplexArray(c, n);
    c = ComputeDFT(arr, n);
    ComputeIDFT(c, n);

    return 0;
}

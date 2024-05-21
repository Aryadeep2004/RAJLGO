#include <stdio.h> 
#include <stdlib.h> 
 
#define MAX 100 
 
int min(int p, int q) 
{ 
    return (p > q) ? q : p; 
} 
 
int max(int p, int q) 
{ 
    return (p > q) ? p : q; 
} 
 
int* Batcher(int* U, int* V, int m, int n) 
{ 
    if (m == 0 && n == 0) 
    { 
        return NULL; 
    } 
    else if (n == 0) 
    { 
        int* S = (int*)malloc(m * sizeof(int)); 
        for (int i = 0; i < m; i++) 
        { 
            S[i] = U[i]; 
        } 
        return S; 
    } 
    else if (m == 0) 
    { 
        int* S = (int*)malloc(n * sizeof(int)); 
        for (int i = 0; i < n; i++) 
        { 
            S[i] = V[i]; 
        } 
        return S; 
    }
    else if (m == 1 && n == 1) 
    { 
        int* S = (int*)malloc(2 * sizeof(int)); 
        S[0] = min(U[0], V[0]); 
        S[1] = max(U[0], V[0]); 
        return S; 
    } 
    else 
    { 
        int x, k, y; 
        if (m % 2 == 0) 
        { 
            x = m / 2; 
        } else { 
            x = (m / 2) + 1; 
        } 
        if (n % 2 == 0) 
        { 
            y = n / 2; 
        } 
        else 
        { 
            y = (n / 2) + 1; 
        } 
        int* Ou = (int*)malloc(x * sizeof(int)); 
        k = 0; 
        for (int i = 0; i < m; i += 2) 
        { 
            Ou[k++] = U[i]; 
        } 
        int* Ov = (int*)malloc(y * sizeof(int)); 
        k = 0; 
        for (int i = 0; i < n; i += 2)
        { 
            Ov[k++] = V[i]; 
        } 
        int* A = Batcher(Ou, Ov, x, y); 
        free(Ou); 
        free(Ov); 
        int* Eu = (int*)malloc((m / 2) * sizeof(int)); 
        k = 0; 
        for (int i = 1; i < m; i += 2) 
        { 
            Eu[k++] = U[i]; 
        } 
        int* Ev = (int*)malloc((n / 2) * sizeof(int)); 
        k = 0; 
        for (int i = 1; i < n; i += 2) 
        { 
            Ev[k++] = V[i]; 
        } 
        int* B = Batcher(Eu, Ev, m / 2, n / 2); 
        free(Eu); 
        free(Ev); 
        int c; 
        if (m % 2 == 0 && n % 2 == 0) 
        { 
            c = (m / 2) + (n / 2) - 1; 
        } 
        else 
        { 
            c = (m / 2) + (n / 2); 
        } 
        int* S = (int*)malloc((m + n) * sizeof(int)); 
        k = 0; 
        S[k++] = A[0]; 
        for (int i = 1; i <= c; i++)
        { 
            S[k++] = min(A[i], B[i - 1]); 
            S[k++] = max(A[i], B[i - 1]); 
        } 
        if (m % 2 == 0 && n % 2 == 0) 
        { 
            S[k++] = B[c]; 
        } 
        else if (m % 2 != 0 && n % 2 != 0) 
        { 
            S[k++] = A[c]; 
        } 
        free(A); 
        free(B); 
        return S; 
    } 
} 
 
int* Batchers(int ar[], int st, int n) 
{ 
    int* S; 
    if (n > 1) 
    { 
        int* U = Batchers(ar, st, n / 2); 
        int* V = Batchers(ar, st + (n / 2), n - (n / 2)); 
        S = Batcher(U, V, n / 2, n - (n / 2)); 
        free(U); 
        free(V); 
    }
    else 
    { 
        S = (int*)malloc(sizeof(int)); 
        S[0] = ar[st]; 
    } 
    return S; 
} 
 
int main() 
{ 
    int ar[MAX], n; 
    printf("Enter number of elements: "); 
    scanf("%d", &n); 
    for (int i = 0; i < n; i++) 
    { 
        printf("Enter %d element in array: ", i + 1); 
        scanf("%d", &ar[i]); 
    } 
    int* s = Batchers(ar, 0, n); 
    printf("Sorted array: "); 
    for (int i = 0; i < n; i++) 
    { 
        printf("%d ", s[i]); 
    } 
    free(s); 
    return 0; 
}


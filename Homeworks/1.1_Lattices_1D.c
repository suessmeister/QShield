#include <stdio.h>
#include <stdlib.h>

int euc_alg(int a[], int s, int c, int v)
{
    if (c < s - 1)
    {
        int temp_1 = a[c];
        int temp_2 = a[c + 1];

        // iterative version of the two part problem
        if (v != -1) {
            a[c] = v;
        }

        while (a[c] != 0 && a[c + 1] != 0)
        {
            int r = a[c] % a[c + 1];
            a[c] = a[c + 1];
            a[c + 1] = r;
        }

        if (a[c] == 0)
        {
            v = a[c + 1];
        }
        else
        {
            v = a[c];
        }
        a[c] = temp_1;
        a[c+1] = temp_2;
        euc_alg(a, s, c + 1, v);
    } else {
        return v;
    }
}

int main()
{
    // this is because otherwise for whatever reason it gives us the same "random" number LOL
    int _1_d_Lattice_Vectors[] = {900, 72, -6, 2, 1};

    // Euclidean Algorithm for finding the GCD. Now generalizing to some nth
    int size = sizeof(_1_d_Lattice_Vectors) / sizeof(int);
    int counter = 0;
    int v = -1;
    int result = euc_alg(_1_d_Lattice_Vectors, size, counter, v);

    for (int i = 0; i < size; i++)
    {
        printf("element at index %d is %d\n", i, _1_d_Lattice_Vectors[i]);
    }

    printf("final result is %d\n", result);

    return 0;
}

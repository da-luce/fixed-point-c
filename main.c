
#include <stdio.h>
#include <math.h>

typedef signed int fix15;

#define fix15_to_float(a) ((float)(a)/32768.0)
#define float_to_fix15(a) ((fix15)((a)*32768.0))

#define fix15_to_int(a) ((int)(a >> 15))
#define int_to_fix15(a) ((fix15)(a << 15))

#define char_to_fix15(a) (fix15)(((fix15)(a)) << 15)

#define abs_fix15(a) abs(a)
#define mult_fix15(a,b) ((fix15)((((signed long long)(a))*((signed long long)(b)))>>15))
#define div_fix15(a,b) (fix15)( (((signed long long)(a)) << 15) / (b))

int main()
{
    unsigned int fractional_bits;

    printf("Enter fractional bits: ");
    scanf("%u", &fractional_bits);

    if (fractional_bits < 1)
    {
        printf("Fractional bits must be >= 1\n");
        return -1;
    }

    if (fractional_bits >= 30)
    {
        printf("Fractional bits must be <= 30\n");
        return -1;
    }

    unsigned int decimal_bits = 32 - 1 - fractional_bits;

    unsigned int max_decimal = (1u << decimal_bits) - 1;
    float max_fractional = 1.0f - (1.0f / powf(2, fractional_bits));

    char buffer[32];
    snprintf(buffer, sizeof(buffer), "%.9f", max_fractional);

    float fractional_res = 1.0f / powf(2, fractional_bits);
    printf("Fractional resolution: %f\n", fractional_res);
    printf("Maximum absolute value of fix%u: %u.%s\n", fractional_bits, max_decimal, buffer + 2);
    return 0;
}
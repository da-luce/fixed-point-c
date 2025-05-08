# Fixed Point Macro Generation for C

Generate macros for a variable number of decimal and fractional bits:

```c
typedef signed int fix15;

#define fix15_to_float(a) ((float)(a)/32768.0)
#define float_to_fix15(a) ((fix15)((a)*32768.0)) 

#define fix15_to_int(a) ((int)(a >> 15))
#define int_to_fix15(a) ((fix15)(a << 15))

#define char_to_fix15(a) (fix15)(((fix15)(a)) << 15)

#define abs_fix15(a) abs(a) 
#define mult_fix15(a,b) ((fix15)((((signed long long)(a))*((signed long long)(b)))>>15))
#define div_fix15(a,b) (fix15)( (((signed long long)(a)) << 15) / (b))
```

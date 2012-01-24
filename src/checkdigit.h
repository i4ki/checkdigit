#ifndef __DV_H
#define __DV_H

#define ASSERT_DV(expected, dv, number, algorithm_name) \
    if (dv != expected) \
    { \
        fprintf(stdout, "[FAIL] %s: \t\tcomparison fail, %u != %u === algorithm '%s' \n", number, expected, dv, algorithm_name); \
    } else { \
        fprintf(stdout, "[OK] %s: \t\t%s-%u == algorithm '%s'\n", number, number, dv, algorithm_name); \
    }

#define THROW_ERROR_RANGE(n) \
            do { \
            fprintf(stderr, "error, number '%u' out of digit range\n", n); \
            exit(1); } while(0) 


#define ASCII_0 48
#define GETINT(a) (a-ASCII_0)

extern unsigned dv_precatorio_sc(char processo[12]);
extern unsigned mod11_generic(const char*,unsigned,unsigned);
extern unsigned mod11_impl1(const char*);
extern unsigned mod11_impl2(const char*);
extern unsigned mod11_reverse_impl1(const char*);
extern unsigned mod11_reverse_impl2(const char*);
extern unsigned mod10_generic(const char*, unsigned short);
extern unsigned mod10_impl1(const char*);
extern unsigned mod10_impl2(const char*);

#endif

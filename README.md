*This project has been created as part of the 42 curriculum by MelineGogjyan.*

# ft_printf

## Description
`ft_printf` is a custom implementation of the standard C `printf` function.  
The goal of this project is to recreate the behavior of `printf` for a subset of format specifiers:  
- `%c` — character  
- `%s` — string  
- `%d` / `%i` — signed integers  
- `%u` — unsigned integers  
- `%x` / `%X` — hexadecimal numbers (lowercase/uppercase)  
- `%p` — pointers  
- `%%` — percent sign  

This project helps to understand variadic functions, recursion, and low-level I/O with `write`.

---
## Instructions
To compile the library:

This will create a static library `libftprintf.a` from the following sources:

- `ft_printf.c`
- `handle_format.c`
- `print_char.c`
- `print_string.c`
- `print_number.c`
- `print_unsigned.c`
- `print_hex.c`
- `print_pointer.c`
To test `ft_printf`, create a separate `main.c` file, include the header:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s! Number: %d\n", "42", 123);
    return 0;
}
```

Compile with:

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o test
```

Then run:

```bash
./test
```

---

## Resources

Classic references used for understanding `printf` and variadic functions:

- [C Standard Library Documentation](https://www.cplusplus.com/reference/cstdio/printf/)
- [man 3 printf](https://man7.org/linux/man-pages/man3/printf.3.html)
- Tutorials on variadic functions and recursion in C

AI Assistance:

- Helped to clarify implementation details for variadic functions (`va_list`, `va_arg`)
- Advised on recursion for number and hexadecimal printing    
- Suggested edge cases tests (e.g., `INT_MIN`, `NULL` pointers, `%x` zero)
- Assisted with README formatting and structuring explanations

---

## Algorithm and Data Structures

- **Algorithm**:
    
    - Parsing the format string character by character
        
    - When `%` is encountered, call `handle_format` to dispatch the appropriate printing function
        
    - For numbers, recursion is used to print each digit from most significant to least significant
        
    - For hexadecimal and pointers, recursion is used to handle variable-length digits
        
    - Length of printed characters is tracked for each function and summed in `ft_printf`
        
- **Data Structures**:
    
    - No complex data structures are required for this project
        
    - Only basic C types (`int`, `unsigned int`, `unsigned long`, `char *`) and variadic arguments (`va_list`)
        

---

## Additional Notes

- All output is performed using the `write` system call
    
- Edge cases are handled for:
    
    - `NULL` strings and pointers
        
    - `0` for numbers and hexadecimals
        
    - `INT_MIN` for signed integers
        
- The library is compliant with the Norm (42 coding standard)
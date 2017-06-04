Jingke Xu's tutorial on how to program in C++ using a generic Makefile

You can use the Makefile in this folder to compile a variety of codes you write if you follow these rules:
1. A header file can be either .h or .hh.
2. All .cpp files in any directory will be automatically detected, dependency-resolved, and compiled.
3. All .cpp files in the directory exe/ will be made into an executable (you need to define a main() function).
4. All .cpp files in other directories than exe/ can not have main() function.
5. If you don't want a file to be compiled automatically, name it .C (or anything other than .h, .hh, .cpp)

Enjoy!

#ifndef MathExports_h
#define MathExports_h

#ifdef _WIN32
    #ifdef math_EXPORTS
        #define  MATH_EXPORT __declspec( dllexport )
    #else
        #define  MATH_EXPORT __declspec( dllimport )
    #endif
#else
    #define    MATH_EXPORT
#endif

#endif // MathExports_h

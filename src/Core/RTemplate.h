#if _Attr == 1
    #define __Attr _, _T1
#endif
#if _Attr == 2
    #define __Attr _, _T1, _, _T2
#endif
#if _Attr == 3
    #define __Attr _, _T1, _, _T2, _, _T3
#endif
#if _Attr == 4
    #define __Attr _, _T1, _, _T2, _, _T3, _, _T4
#endif
#undef _RTClassName
#define _RTClassName _C(_ClassName, __Attr)

#include _E(_RTAddress)

#undef _T1
#undef _T2
#undef _T3
#undef _T4
#undef __Attr


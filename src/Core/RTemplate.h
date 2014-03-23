#if _Attr == 1
    #define __Attr _T1
#endif
#if _Attr == 2
    #define __Attr _T1, _, _T2
#endif
#if _Attr == 3
    #define __Attr _T1, _, _T2, _, _T3
#endif
#if _Attr == 4
    #define __Attr _T1, _, _T2, _, _T3, _, _T4
#endif

#define _T1_TID _C(_TID, _, _T1)
#define _T2_TID _C(_TID, _, _T2)
#define _T3_TID _C(_TID, _, _T3)
#define _T4_TID _C(_TID, _, _T4)

#undef _T1_IntLike
#undef _T1_FloatLike
#if _T1_TID <= _TID_Double
    #define _T1_FloatLike
#else
    #define _T1_IntLike
#endif

#undef _T2_IntLike
#undef _T2_FloatLike
#if _T2_TID <= _TID_Double
    #define _T2_FloatLike
#else
    #define _T2_IntLike
#endif

#undef _T3_IntLike
#undef _T3_FloatLike
#if _T3_TID <= _TID_Double
    #define _T3_FloatLike
#else
    #define _T3_IntLike
#endif

#undef _T4_IntLike
#undef _T4_FloatLike
#if _T4_TID <= _TID_Double
    #define _T4_FloatLike
#else
    #define _T4_IntLike
#endif

#undef _RTClassName
#if _Attr == 1
    #define _RTClassName _C1(_ClassName, __Attr)
#else
    #define _RTClassName _C(_ClassName, __Attr)
#endif
#include _E(_RTAddress)

#undef _T1
#undef _T2
#undef _T3
#undef _T4
#undef __Attr


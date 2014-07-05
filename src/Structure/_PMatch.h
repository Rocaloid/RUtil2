RClass(_RTClassName)
{
    RInherit(RObject);
    Array_Define(_T1, X);
    Array_Define(_T2, Y);
};

RTMethod(void, PMatch, From, _RTClassName* Sorc);
RTMethod(void, PMatch, AddPair, _T1 XVar, _T2 YVar);
RTMethod(void, PMatch, Clear);
RTMethod(void, PMatch, Print);
RTMethod(_C(Transition, RTAttr_2), PMatch, Query, _T1 XVar);


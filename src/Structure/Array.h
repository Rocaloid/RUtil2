#ifndef ARRAY_H
#define ARRAY_H

#include <malloc.h>
#define Array_Addition 100

#define _ProtoArray_Resize(Type, Array, IndexNumber, Size, NewSize) \
    do{ \
        (Array) = (Type*)realloc((Array), sizeof(Type) * (NewSize)); \
        (Size) = NewSize; \
        if((NewSize) <= (IndexNumber)) \
            (IndexNumber) = (NewSize) - 1; \
    }while(0)

#define _ProtoArray_Push(Type, Array, IndexNumber, Size, Data) \
    do{ \
        if((IndexNumber) > (Size) - 2) \
        { \
            (Array) = (Type*)realloc((Array), sizeof(Type) * \
                      ((Array_Addition) + (Size))); \
            (Size) += Array_Addition; \
        } \
        (Array)[++ IndexNumber] = Data; \
    }while(0)

#define _ProtoArray_PushNull(Type, Array, IndexNumber, Size) \
    do{ \
        if((IndexNumber) > (Size) - 2) \
        { \
            (Array) = (Type*)realloc((Array), sizeof(Type) * \
                      ((Array_Addition) + (Size))); \
            (Size) += Array_Addition; \
        } \
        (IndexNumber) ++; \
    }while(0)

#define _ProtoArray_Pop(Type, Array, IndexNumber, Size) \
    ((Array)[IndexNumber --])

#define _ProtoArray_Insert(Type, Array, IndexNumber, Size, Index, Data) \
    do{ \
        int Array_i; \
        if((IndexNumber) > (Size) - 2) \
        { \
            (Array) = (Type*)realloc((Array), sizeof(Type) * \
                      ((Array_Addition) + (Size))); \
            (Size) += Array_Addition; \
        } \
        for(Array_i = (IndexNumber) + 1; Array_i > (Index); Array_i --) \
            (Array)[Array_i] = (Array)[Array_i - 1]; \
        (Array)[Index] = Data; \
        (IndexNumber) ++; \
    }while(0)

#define _ProtoArray_InsertNull(Type, Array, IndexNumber, Size, Index) \
    do{ \
        int Array_i; \
        if((IndexNumber) > (Size) - 2) \
        { \
            (Array) = (Type*)realloc((Array), sizeof(Type) * \
                      ((Array_Addition) + (Size))); \
            (Size) += Array_Addition; \
        } \
        for(Array_i = (IndexNumber) + 1; Array_i > (Index); Array_i --) \
            (Array)[Array_i] = (Array)[Array_i - 1]; \
        (IndexNumber) ++; \
    }while(0)

#define _ProtoArray_Remove(Type, Array, IndexNumber, Size, Index) \
    do{ \
        int Array_i; \
        for(Array_i = (Index); Array_i < (IndexNumber); Array_i ++) \
            (Array)[Array_i] = (Array)[Array_i + 1]; \
        (IndexNumber) --; \
    }while(0)

#define _ProtoArray_RemoveRange(Type, Array, IndexNumber, Size, \
    LIndex, HIndex) \
    do{ \
        int Array_i; \
        int Array_RemoveAmount = (HIndex) - (LIndex) + 1; \
        for(Array_i = (LIndex); Array_i < (IndexNumber) - (HIndex - LIndex); \
            Array_i ++) \
            (Array)[Array_i] = (Array)[Array_i + Array_RemoveAmount]; \
        (IndexNumber) -= Array_RemoveAmount; \
    }while(0)

#define Array_Define(Type, Name) \
    Type* Name; \
    int Name##_Index; \
    int Name##_Size

#define Array_Gtor(Type, Name) \
    Type* Name = (Type*)malloc(sizeof(Type) * 10); \
    int Name##_Index = -1; \
    int Name##_Size = 10

#define Array_Ctor(Type, Name) \
    Name = (Type*)malloc(sizeof(Type) * 10); \
    Name##_Index = -1; \
    Name##_Size = 10

#define Array_Dtor(Type, Name) \
    free(Name)

#define Array_ObjDtor(Type, Name); \
    do{ \
        int Array_i; \
        for(Array_i = 0; Array_i <= Name##_Index; Array_i ++) \
            Type##_Dtor(Name + Array_i); \
    }while(0)

#define Array_Resize(Type, Array, NewSize) \
    _ProtoArray_Resize(Type, Array, Array##_Index, Array##_Size, NewSize)

#define Array_Push(Type, Array, Data) \
    _ProtoArray_Push(Type, Array, Array##_Index, Array##_Size, Data)

#define Array_PushNull(Type, Array) \
    _ProtoArray_PushNull(Type, Array, Array##_Index, Array##_Size)

#define Array_PushObj(Type, Array, ObjRef) \
    _ProtoArray_PushNull(Type, Array, Array##_Index, Array##_Size); \
    Type##_Ctor(& Array[Array##_Index]);\
    Type##_Copy(& Array[Array##_Index], ObjRef)

#define Array_Pop(Type, Array) \
    _ProtoArray_Pop(Type, Array, Array##_Index, Array##_Size)

#define Array_Insert(Type, Array, Index, Data) \
    _ProtoArray_Insert(Type, Array, Array##_Index, Array##_Size, Index, Data)

#define Array_InsertNull(Type, Array, Index) \
    _ProtoArray_InsertNull(Type, Array, Array##_Index, Array##_Size, Index)

#define Array_Remove(Type, Array, Index) \
    _ProtoArray_Remove(Type, Array, Array##_Index, Array##_Size, Index)

#define Array_RemoveRange(Type, Array, LIndex, HIndex) \
    _ProtoArray_RemoveRange(Type, Array, Array##_Index, Array##_Size, \
        LIndex, HIndex)

//---------------------Advanced Macros--------------------
#define Array_IncFind(Dest, Type, Array, Data) \
    do \
    { \
        int Array_i; \
        for(Array_i = 0; Array_i <= Array##_Index; Array_i ++) \
            if((Array)[Array_i] > (Data)) \
                break; \
        Dest = Array_i; \
    } while(0)

#define Array_DecFind(Dest, Type, Array, Data) \
    do \
    { \
        int Array_i; \
        for(Array_i = 0; Array_i <= Array##_Index; Array_i ++) \
            if(Array[Array_i] < (Data)) \
                break; \
        Dest = Array_i; \
    } while(0)

//---------------------Auxillaries------------------------

#define TopOf(Array) Array[Array##_Index]

#define Array_Par(Type, Array) Type* Array, int Array##_Index, int Array##_Size
#define Array_Arg(Type, Array) Array, Array##_Index, Array##_Size

#endif


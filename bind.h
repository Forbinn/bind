/*
** bind.h for Perso in /Users/leroy_v/Perso
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Mer jui 25 22:56:44 2014 vincent leroy
** Last update Lun jui 30 20:57:28 2014 vincent leroy
*/

#ifndef BIND_H_
# define BIND_H_

#if !defined(__GNUC__) || defined(__clang__)
#error "You can only use bind macro with gcc compiler"
#else

#define bind1(retType, func, argType1, ...) \
    ({ \
        retType anonymous(argType1 a) \
        { return (*(func))(__VA_ARGS__, a); } \
        (void*)&anonymous; \
    })

#define bind2(retType, func, argType1, argType2, ...) \
    ({ \
        retType anonymous(argType1 a, argType2 b) \
        { return (*(func))(__VA_ARGS__, a, b); } \
        (void*)&anonymous; \
    })

#define bind3(retType, func, argType1, argType2, argType3, ...) \
    ({ \
        retType anonymous(argType1 a, argType2 b, argType3 c) \
        { return (*(func))(__VA_ARGS__, a, b, c); } \
        (void*)&anonymous; \
    })

// This part is still in progress
#if 0
#define __ARGS__(x1, x2, x3, N, ...) N
#define GET_BIND(...)   __ARGS__(__VA_ARGS__, bind3, bind2, bind1)

#define bind(retType, func, ...)    GET_BIND(typeof(func))(retType, func, __VA_ARGS__)
#endif

#endif /* !__GNUC__ || __clang__ */

#endif /* !BIND_H_ */

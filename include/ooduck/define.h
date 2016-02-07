#ifndef __OODUCK_DEFINE_H
#define __OODUCK_DEFINE_H

#define OODUCK_DECLARE_CLASS(N) \
    const void *N (void)

#ifdef HAVE_PTHREAD
#   include <pthread.h>

#   define OODUCK_DEFINE_CLASS(N, _C_)                         \
        pthread_once_t N##Initialized = PTHREAD_ONCE_INIT;  \
        static const void *_##N = NULL;                     \
                                                            \
        static void N##_safeinit (void)                     \
        {                                                   \
            _##N = _C_;                                     \
        }                                                   \
                                                            \
        const void *N (void)                                \
        {                                                   \
            pthread_once (&N##Initialized, N##_safeinit);   \
            return _##N;                                    \
        }
#else
#   define OODUCK_DEFINE_CLASS(N, _C_)                         \
        pthread_once_t N##Initialized = PTHREAD_ONCE_INIT;  \
        static const void *_##N = NULL;                     \
                                                            \
        const void *N (void)                                \
        {                                                   \
            if (_##N == NULL)                               \
            {                                               \
                _##N = _C_;                                 \
            }                                               \
                                                            \
            return _##N;                                    \
        }
#endif

#endif /* __OODUCK_DEFINE_H */
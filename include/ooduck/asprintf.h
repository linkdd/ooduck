#ifndef __OODUCK_ASPRINTF_H
#define __OODUCK_ASPRINTF_H

int vasprintf (char **ret, const char *fmt, va_list args);
int asprintf (char **ret, const char *fmt, ...);

#endif /* __OODUCK_ASPRINTF_H */

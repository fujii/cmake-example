#ifndef LIBHELLO_EXPORT_H
#define LIBHELLO_EXPORT_H
#pragma once

#if defined _WIN32 || defined __CYGWIN__
  #ifdef LIBHELLO_STATIC
    #define LIBHELLO_API
  #else
    #ifdef LIBHELLO_EXPORTS
      #ifdef __GNUC__
        #define LIBHELLO_API __attribute__((dllexport))
      #else
        #define LIBHELLO_API __declspec(dllexport)
      #endif
    #else
      #ifdef __GNUC__
        #define LIBHELLO_API __attribute__((dllimport))
      #else
        #define LIBHELLO_API __declspec(dllimport)
      #endif
    #endif
  #endif
#else
  #if __GNUC__ >= 4 && !defined(__OS2__)
    #define LIBHELLO_API __attribute__((visibility("default")))
  #else
    #define LIBHELLO_API
  #endif
#endif

#endif /* LIBHELLO_EXPORT_H */

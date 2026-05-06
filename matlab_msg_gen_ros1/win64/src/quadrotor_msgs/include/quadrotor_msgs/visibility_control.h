#ifndef QUADROTOR_MSGS__VISIBILITY_CONTROL_H_
#define QUADROTOR_MSGS__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define QUADROTOR_MSGS_EXPORT __attribute__ ((dllexport))
    #define QUADROTOR_MSGS_IMPORT __attribute__ ((dllimport))
  #else
    #define QUADROTOR_MSGS_EXPORT __declspec(dllexport)
    #define QUADROTOR_MSGS_IMPORT __declspec(dllimport)
  #endif
  #ifdef QUADROTOR_MSGS_BUILDING_LIBRARY
    #define QUADROTOR_MSGS_PUBLIC QUADROTOR_MSGS_EXPORT
  #else
    #define QUADROTOR_MSGS_PUBLIC QUADROTOR_MSGS_IMPORT
  #endif
  #define QUADROTOR_MSGS_PUBLIC_TYPE QUADROTOR_MSGS_PUBLIC
  #define QUADROTOR_MSGS_LOCAL
#else
  #define QUADROTOR_MSGS_EXPORT __attribute__ ((visibility("default")))
  #define QUADROTOR_MSGS_IMPORT
  #if __GNUC__ >= 4
    #define QUADROTOR_MSGS_PUBLIC __attribute__ ((visibility("default")))
    #define QUADROTOR_MSGS_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define QUADROTOR_MSGS_PUBLIC
    #define QUADROTOR_MSGS_LOCAL
  #endif
  #define QUADROTOR_MSGS_PUBLIC_TYPE
#endif
#endif  // QUADROTOR_MSGS__VISIBILITY_CONTROL_H_
// Generated 05-May-2026 16:37:58
// Copyright 2019-2020 The MathWorks, Inc.

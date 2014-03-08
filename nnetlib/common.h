#ifndef _NNET
#define _NNET

#ifdef COMPILE_NNET
  #define NNET_DLL __declspec(dllexport)
#else
  #define NNET_DLL __declspec(dllimport)
#endif

#endif
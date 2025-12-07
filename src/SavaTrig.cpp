/*
  SavaTrig.cpp - Реализация библиотеки SavaTrig
*/

#include "SavaTrig.h"

// Конструктор
SavaTrig::SavaTrig() {
  _state = 0;
}

// R_TRIG
bool SavaTrig::RT(bool input) {
  bool lastState = (_state >> BIT_RT_LAST) & 1;
  bool detected = (input && !lastState);
  
  if (input) _state |= (1 << BIT_RT_LAST);
  else       _state &= ~(1 << BIT_RT_LAST);
  
  return detected;
}

// F_TRIG
bool SavaTrig::FT(bool input) {
  bool lastState = (_state >> BIT_FT_LAST) & 1;
  bool detected = (!input && lastState);
  
  if (input) _state |= (1 << BIT_FT_LAST);
  else       _state &= ~(1 << BIT_FT_LAST);
  
  return detected;
}

// T_TRIG
bool SavaTrig::TT(bool input) {
  bool lastState = (_state >> BIT_TT_LAST) & 1;
  
  if (input && !lastState) {
    _state ^= (1 << BIT_TT_OUT); // Инверсия выхода
  }
  
  if (input) _state |= (1 << BIT_TT_LAST);
  else       _state &= ~(1 << BIT_TT_LAST);
  
  return (_state >> BIT_TT_OUT) & 1;
}

// RS_TRIG
bool SavaTrig::RS(bool set, bool reset) {
  if (reset)      _state &= ~(1 << BIT_RS_OUT);
  else if (set)   _state |= (1 << BIT_RS_OUT);
  
  return (_state >> BIT_RS_OUT) & 1;
}

// SR_TRIG
bool SavaTrig::SR(bool set, bool reset) {
  if (set)        _state |= (1 << BIT_SR_OUT);
  else if (reset) _state &= ~(1 << BIT_SR_OUT);
  
  return (_state >> BIT_SR_OUT) & 1;
} 
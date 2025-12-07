/*
  SavaTrig.h - Библиотека логических триггеров
  Автор: SavaLab <sava-74@inbox.ru>
  GitHub: https://github.com/sava-74/SavaTrigger.git
*/

#ifndef SavaTrig_h
#define SavaTrig_h

#include <Arduino.h>

class SavaTrig {
  public:
    /**
     * @brief Конструктор.
     */
    SavaTrig();

    /**
     * @brief R_TRIG: Детектор переднего фронта (Rising Edge).
     * @return true (один цикл) при переходе 0 -> 1.
     */
    bool RT(bool input);

    /**
     * @brief F_TRIG: Детектор заднего фронта (Falling Edge).
     * @return true (один цикл) при переходе 1 -> 0.
     */
    bool FT(bool input);

    /**
     * @brief T_TRIG: Счетный триггер (Toggle).
     * Работает как кнопка с фиксацией.
     */
    bool TT(bool input);

    /**
     * @brief RS_TRIG: Приоритет сброса (Reset Dominant).
     * @return 0, если оба входа активны.
     */
    bool RS(bool set, bool reset);

    /**
     * @brief SR_TRIG: Приоритет установки (Set Dominant).
     * @return 1, если оба входа активны.
     */
    bool SR(bool set, bool reset);

  private:
    uint8_t _state; // Хранение всех флагов в 1 байте

    enum Flags {
      BIT_RT_LAST = 0,
      BIT_FT_LAST = 1,
      BIT_TT_LAST = 2,
      BIT_TT_OUT  = 3,
      BIT_RS_OUT  = 4,
      BIT_SR_OUT  = 5
    };
};

#endif
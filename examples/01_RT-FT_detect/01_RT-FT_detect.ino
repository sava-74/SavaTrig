//для работы с кнопками установите библиотеку SavaButton https://github.com/sava-74/SavaButton.git
/* Пример 1: Детекторы фронтов (RT и FT)
*  RT (R_TRIG): Сработает один раз в момент нажатия.
*  FT (F_TRIG): Сработает один раз в момент отпускания.
*/

#include <SavaButton.h>
#include <SavaTrig.h>

// Создаем объекты кнопок (Пин, Режим)
// PLUS - значит кнопка замыкает на землю (INPUT_PULLUP)
SavaButton btn;

// Создаем объекты триггеров
SavaTrig trigRT; // Для ловли переднего фронта
SavaTrig trigFT; // Для ловли заднего фронта

void setup() {
  Serial.begin(9600);
  
  // Инициализация кнопки
  btn(12); 
  
  Serial.println("--- Start Example 1: RT & FT ---");
  Serial.println("Press and release the button on pin 12");
}

void loop() {
  // 1. Получаем чистый сигнал (true/false) с кнопки
  bool inputSignal = btn.read();

  // 2. Обрабатываем передний фронт (Нажатие)
  if (trigRT.RT(inputSignal)) {
    Serial.println(">> Событие - передний фронт! (Кнопка нажата)");
  }

  // 3. Обрабатываем задний фронт (Отпускание)
  if (inputSignal) {
    Serial.println("<< Событие - постоянное нажатие ! (Кнопка зажата)");
    delay(250);
  }

  // 4. Обрабатываем задний фронт (Отпускание)
  if (trigFT.FT(inputSignal)) {
    Serial.println("<< Событие - задний фронт! (Кнопка отпущена)");
  }
}
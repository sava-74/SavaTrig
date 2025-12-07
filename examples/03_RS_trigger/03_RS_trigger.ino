/*  Для работы с кнопками установите библиотеку SavaButton https://github.com/sava-74/SavaButton.git
*   Пример использования RS-триггера (SavaTrig)
*  Сценарий: Безопасное управление мотором ("Пуск" и "Стоп")
*  
*  Логика RS (Reset Dominant):
*  - Приоритет всегда у сигнала СБРОСА (Reset).
*  - Если нажаты обе кнопки одновременно -> Мотор ОСТАНОВИТСЯ.
*/

#include <SavaButton.h>
#include <SavaTrig.h>

// Настройка кнопок (режим PLUS - замыкание на GND)
SavaButton btnStart; // Кнопка "Пуск" (SET)
SavaButton btnStop;  // Кнопка "Стоп" (RESET)

SavaTrig motorLogic; // Экземпляр триггера

void setup() {
  Serial.begin(9600);
  
  // Инициализация пинов
  btnStart(12);
  btnStop(15);
  
  Serial.println("--- Пример запуска RS (приоритет безопасности) ---");
  Serial.println("Btn 12: ЗАПУСК (настройка)");
  Serial.println("Btn 15: ОСТАНОВКА (сброс) - ПРИОРИТЕТ!");
}

void loop() {
  // 1. Читаем состояние кнопок
  bool setSignal = btnStart.read();
  bool resetSignal = btnStop.read();

  // 2. Обработка логики RS
  // setSignal -> пытается включить (1)
  // resetSignal -> пытается выключить (0) и имеет приоритет
  bool motorState = motorLogic.RS(setSignal, resetSignal);

  // 3. Вывод информации
  // Выводим статус, чтобы видеть, кто победил
  Serial.print("ВХОДЫ [ Старт:");
  Serial.print(setSignal);
  Serial.print(" Стоп:");
  Serial.print(resetSignal);
  Serial.print(" ]  --->  Выход: ");

  if (motorState) {
    Serial.println("Вкл.  (работа)");
  } else {
    Serial.print("Выкл. (Остановка)");
    // Если нажаты обе, поясняем почему выключено
    if (setSignal && resetSignal) {
      Serial.print(" <- приоритет по сбросу!");
    }
    Serial.println();
  }

  delay(100); // Небольшая задержка для читаемости лога
}